#include <iostream>
using namespace std;

float f[1005] = {0}, tmp[1005] = {0}, mem[1005] = {0};
int n, lans[1005] = {0}, rans[1005] = {0};

int lcs(int len)
{
	int i, ans = 1;
	for (i = 0; i < len; i++)
	{
		mem[i] = 0;
	}
	mem[0] = tmp[0];
	for (i = 1; i < len; i++)
	{
		if (tmp[i] > mem[ans-1])
		{
			mem[ans] = tmp[i];
			ans++;
		}
		else
		{
			int left = 0, right = ans-1;
			while (right > left)
			{
				int mid = (left+right)/2;
				if (tmp[i] <= mem[mid])
				{
					right = mid;
				}
				else
				{
					left = mid+1;
				}
			}
			mem[left] = tmp[i];
		}
	}
	return ans;
}

int main()
{
	cin >> n;
	int i, j;
	for (i = 0; i < n; i++)
	{
		cin >> f[i];
	}
	int ans = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			tmp[j] = f[j];
		}
		lans[i] = lcs(i+1);
		for (j = n-1; j >= i; j--)
		{
			tmp[n-1-j] = f[j];
		}
		rans[i] = lcs(n-i);
	}
	for (i = 0; i < n; i++)
		for (j = i; j < n; j++)
		{
			if (lans[i]+rans[j]-(i==j) > ans)
			{
				ans = lans[i]+rans[j]-(i==j);
			}
		}
	cout << n-ans;
	return 0;
}
