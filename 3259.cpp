#include<iostream>
using namespace std;
int main()
{
	long i,n,t=0;
	cin>>n;
	if(n==4)
		for(i=1000;i<=9999;i++)
		{
			if((i/100+i%100)*(i/100+i%100)==i&&t==0)
			{
				cout<<i;
				t=1;
			}
			else if((i/100+i%100)*(i/100+i%100)==i&&t==1)cout<<' '<<i;
		}
	if(n==6)
		for(i=100000;i<=999999;i++)
		{
			if((i/1000+i%1000)*(i/1000+i%1000)==i&&t==0)
			{
				cout<<i;
				t=1;
			}
			else if((i/1000+i%1000)*(i/1000+i%1000)==i&&t==1)cout<<' '<<i;
		}
	return 0;
}