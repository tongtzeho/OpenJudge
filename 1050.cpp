#include<iostream>
using namespace std;
int sum[2][125001]={0};
char a[501][501]={0};
int main()
{
	int n,i,j,k,s,m,most=0;
	short temp;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		s=1;
		for(j=1;j<=n;j++)
		{
			cin>>temp;
			a[i][j]=temp;
			m=0;
			for(k=j;k>=1;k--)
			{
				m+=a[i][k];
				sum[i%2][s]=m;
				if(sum[(i+1)%2][s]>0) sum[i%2][s]+=sum[(i+1)%2][s];
				if(sum[i%2][s]>most) most=sum[i%2][s];
				s++;
			}
		}
	}
	cout<<most;
	return 0;
}
