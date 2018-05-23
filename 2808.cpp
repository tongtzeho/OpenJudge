#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int l=0,m=0,i=0,a[10001],sum=0,begin,end,j=0;
	for(i=0;i<=10000;i++)
		a[i]=1;
	cin>>l>>m;
	for(i=1;i<=m;i++)
	{
		cin>>begin>>end;
		for(j=begin;j<=end;j++)
			a[j]=0;
	}
	for(i=0;i<=l;i++)
		if(a[i]==1) sum++;
	cout<<sum;
	return 0;
}