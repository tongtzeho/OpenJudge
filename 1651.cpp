#include <iostream>

using namespace std;

int mem[103][103][103]={0};

int main()
{
	int n;
	int a[103];
	int i,j,k,l;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=2;i<=n-1;i++)
		mem[i][i-1][i+1]=a[i-1]*a[i]*a[i+1];
	for(i=3;i<=n-1;i++)
		for(j=1;i+j<=n;j++)
			for(k=j+1;k<=j+i-1;k++)
			{
				int m1=0,m2=0;
				for(l=j+1;l<k;l++)
					if(mem[l][j][k]<m1||m1==0)m1=mem[l][j][k];
				for(l=k+1;l<i+j;l++)
					if(mem[l][k][i+j]<m2||m2==0)m2=mem[l][k][i+j];
				mem[k][j][i+j]=m1+m2+a[k]*a[j]*a[i+j];
			}
	int ans=2147483647;
	for(i=2;i<n;i++)
		if(mem[i][1][n]<ans)ans=mem[i][1][n];
	cout<<ans;
	return 0;
}