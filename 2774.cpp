#include<iostream>
using namespace std;
int main()
{
	int n,k,i,j,max=0,*a,ky;
	cin>>n>>k;
	a=new int[n+1];
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>max)max=a[i];
	}
	for(i=max;i>=1;i--)
	{
		ky=0;
		for(j=1;j<=n;j++)
			ky+=a[j]/i;
		if(k<=ky)
		{
			cout<<i;
			return 0;
		}
	}
	cout<<0;
	return 0;
}