#include<iostream>
using namespace std;
int main()
{
	int r[101]={0},r2[101]={0},n,k,i,j,m,s,t;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>m;
		for(j=0;j<k;j++)
			r2[j]=r[j];
		for(j=0;j<k;j++)
		{
			s=r[j]+m;
			t=s%k;
			if(s>r[t])r2[t]=s;
		}
		for(j=0;j<k;j++)
			if(r2[j]>r[j])r[j]=r2[j];
	}
	cout<<r[0];
	return 0;
}
