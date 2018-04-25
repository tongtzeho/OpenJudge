#include<iostream>
#include<cmath>
using namespace std;
int main( )
{
	int a1=0,a5=0,a10=0,i,k;
	cin>>k;
	int a[100];
	for(i=1;i<=k;i++)
	{	
		cin>>a[i];
        if (a[i]==1) a1=a1+1;
		if (a[i]==5) a5=a5+1;
		if (a[i]==10) a10=a10+1;
	}
	cout<<a1<<endl<<a5<<endl<<a10;
	return 0;
}