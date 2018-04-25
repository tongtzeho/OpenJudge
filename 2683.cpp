#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int n,i;
	double a=1,b=2,c,s=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		s+=b/a;
		c=b;
		b+=a;
		a=c;
	}
	cout<<setiosflags(ios::fixed)<<setprecision(4)<<s;
	return 0;
}