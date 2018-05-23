#include<iostream>
#include<cmath>
using namespace std;
int main( )
{
	int i,n,s=0;
	cin>>n;
	for(i=1;i<=n;i++)
		if (i%7!=0 && (i%10)!=7 && (i-(i%10))!=70) s=s+i*i;
	cout<<s;
	return 0;
}