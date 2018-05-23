#include<iostream>
using namespace std;
int main( )
{
	int a[10],k,i,sum=0;
	for(i=0;i<=9;i++)
		cin>>a[i];
	cin>>k;
	k=k+30;
	for(i=0;i<=9;i++)
		if (k>=a[i]) sum++;
	cout<<sum;
	return 0;
}