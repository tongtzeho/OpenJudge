#include<iostream>
using namespace std;
int main()
{
	int n,m,i,*a;
	cin>>n>>m;
	a=new int[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
	{
		cout<<a[(i+n-m)%n];
		if(i<n-1)cout<<' ';
	}
	return 0;
}