#include<iostream>
using namespace std;
int main()
{
	int n,i,a[10]={0},t;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>t;
		a[t]=1;
	}
	if(a[1]+a[2]<2&&a[3]+a[4]<2&&a[5]-a[6]==0&&a[7]+a[8]>0)cout<<1;
	else cout<<0;
	return 0;
}