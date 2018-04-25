#include<iostream>
using namespace std;
int main()
{
	int n,m,j,k,a[1003]={0},r[1003]={0},l[1003]={0},maxn=0;
	cin>>m;
	for(j=1;j<=m;j++)
		cin>>a[j];
	for(j=1;j<=m;j++)
		r[j]=l[j]=0;
	maxn=0;
	for(j=m;j>=1;j--)
	{
		r[j]=1;
		for(k=j+1;k<=m;k++)
			if(a[k]<a[j]&&r[k]+1>r[j])r[j]=r[k]+1;
	}
	for(j=1;j<=m;j++)
	{
		l[j]=1;
		for(k=j-1;k>=1;k--)
			if(a[k]<a[j]&&l[k]+1>l[j])l[j]=l[k]+1;
	}
	for(j=1;j<=m;j++)
		if(r[j]+l[j]>maxn)maxn=r[j]+l[j];
	cout<<maxn-1<<endl;
	return 0;
}