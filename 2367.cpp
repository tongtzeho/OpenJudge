#include <iostream>
using namespace std;

int result[105]={0};
bool select[105]={0};
bool m[105][105]={0};

void f(int x,int n)
{
	int i,j;
	for (i=1;i<=n;i++)
	{
		if (!select[i])
		{
			for (j=1;j<=n;j++)
			{
				if (!select[j])
				{
					if (m[j][i])
					{
						break;
					}
				}
			}
			if (j==n+1)
			{
				select[i] = true;
				result[x] = i;
				return;
			}
		}
	}
}

int main()
{
	int i,n;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		int temp;
		while (cin>>temp)
		{
			if (temp == 0)
			{
				break;
			}
			m[i][temp] = 1;
		}
	}
	for (i=1;i<=n;i++)
	{
		f(i,n);
	}
	for (i=1;i<=n;i++)
	{
		cout<<result[i];
		if (i != n) cout<<" ";
	}
	return 0;
}
