#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,m,i,j,k,a[400];
	while(cin>>n>>k>>m)
	{
		if (n==0) break;
		for(i=1;i<=n;i++)
		{
			a[i]=1;
		}
		j=n;
		k--;
		while(j>1)
		{
			for(i=1;i<=m;i++)
				do
				{
					if(k==n) k=1;
					else k++;
				} while(a[k]==0);
			cout<<k<<',';
			a[k]=0;
			j--;
		}
		for(i=1;i<=n;i++)
			if(a[i]==1)
			{
				cout<<i<<endl;
				break;
			}
	}
	return 0;
}
