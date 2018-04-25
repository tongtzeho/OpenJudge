#include<iostream>
#include<cmath>
using namespace std;
int main( )
{
	int i,n,s=1;
	cin>>n;
    for(i=1;i<=n;i++)
		s=s*i;
	cout<<s;
	return 0;
}