#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main( )
{
	int n=0,i=1,j=0;
	double e=1,a=1;
	cin>>n;
    for (i=1;i<=n;i++)
	{
		a=1;
		for (j=1;j<=i;j++)
			a=a/j;
		e+=a;
	}
	cout<<setprecision(10)<<setiosflags(ios::fixed)<<e;
	return 0;
}