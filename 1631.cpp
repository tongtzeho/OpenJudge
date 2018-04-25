#include <stdio.h>

int a[40005];
int n;
int mem[40005];
int ans;

int bisearch(int x, int l, int r)
{
	if (l == r) return l;
	int mid = (l+r)/2;
	if (x <= mem[mid])
	{
		r = mid;
	}
	else
	{
		l = mid+1;
	}
	return bisearch(x, l, r);
}

int main()
{
	int testcase;
	scanf("%d", &testcase);
	while (testcase > 0)
	{
		testcase--;
		scanf("%d", &n);
		int i, j;
		ans = 1;
		for (i = 0; i < n; i++)
			scanf("%d", a+i);
		mem[0] = a[0];
		for (i = 1; i < n; i++)
		{
			if (a[i] > mem[ans-1])
			{
				mem[ans] = a[i];
				ans++;
			}
			else
			{
				j = bisearch(a[i], 0, ans-1);
				mem[j] = a[i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
