#include <iostream>
using namespace std;

int n = 0;
int a[1005] = {0};
int mem[1005] = {0};
int ans = 0;

int main()
{
	cin >> n;
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	ans = 1;
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
			int l = 0, r = ans;
			while (r > l)
			{
				int mid = (l+r)>>1;
				if (a[i] <= mem[mid])
				{
					r = mid;
				}
				else
				{
					l = mid+1;
				}
			}
			mem[l] = a[i];
		}
	}
	cout << ans << endl;
	return 0;
}