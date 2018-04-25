#include<iostream>
using namespace std;
int main()
{
	int a,n,i,sum=0;
	cin>>a;
	for(i=1;i<=5;i++)
	{
		cin>>n;
		if(n<a)sum+=n;
	}
	cout<<sum;
	return 0;
}