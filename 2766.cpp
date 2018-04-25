#include<iostream>
using namespace std;
int sum[101][5051]={0};
int main()
{
	int n,i,j,k,s,m,a[101][101]={0},sum1[101]={0},most=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		s=1;
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];
			m=0;
			for(k=j;k>=1;k--)
			{
				m+=a[i][k];
				sum[i][s]+=m;
				if(sum[i-1][s]>0) sum[i][s]+=sum[i-1][s];
				if(sum[i][s]>most) most=sum[i][s];
				s++;
			}
		}
	}
	cout<<most;
	return 0;
}
