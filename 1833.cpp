#include<iostream>
#include<cmath>
using namespace std;
int m,n,p,a[2000]={0};
void next()
{
    int i,j,t,s,k;
	i=n;
	while(a[i-1]>a[i])
	{
		i--;
	}
	t=i;
	if(t==1)
	{
		for(i=1;i<=n;i++)
			a[i]=i;
		return;
	}
	for(j=i;j<=n;j++)
		if(a[j]<a[t]&&a[j]>a[i-1])t=j;
	s=a[i-1];
	a[i-1]=a[t];
	a[t]=s;
	for(j=i;j<=n;j++)
		for(k=j+1;k<=n;k++)
			if(a[j]>a[k])
			{
				s=a[j];
				a[j]=a[k];
				a[k]=s;
			}
}
int main()
{
	int i,j;
	cin>>m;
	for(i=1;i<=m;i++)
	{
		cin>>n>>p;
		for(j=1;j<=n;j++)
			cin>>a[j];
		for(j=1;j<=p;j++)
			next();
		for(j=1;j<=n-1;j++)
			cout<<a[j]<<' ';
		cout<<a[n]<<endl;
	}
	return 0;
}