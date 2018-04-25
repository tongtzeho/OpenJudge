#include<iostream>
using namespace std;
int reverse(int a)
{
	int n=0;
	while(a>0)
	{
		n=n*10+a%10;
		a/=10;
	}
	return n;
}
int main()
{
	int n,a,b,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a>>b;
		cout<<reverse(reverse(a)+reverse(b))<<endl;
	}
	return 0;
}