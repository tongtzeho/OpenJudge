#include<iostream>
using namespace std;
int main()
{
	int i,a,b[200]={0};
	cin>>a;
	i=-1;
	while(a>0)
	{
		i++;
		b[i]=a%8;
		a/=8;
	}
	while(i>=0)
	{
		cout<<b[i];
		i--;
	}
	return 0;
}