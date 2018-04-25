#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,a,b,c,d;
	double x;
	while(cin>>n)
	{
		x=-0.5+sqrt(0.25+2*n);
		if(fabs(x-int(x))<1e-8)c=int(x);
		else c=int(x)+1;
		d=c*(c+1)/2;
		if(c%2==1)
		{
			a=d-n+1;
			b=c+1-a;
		}
		else
		{
			b=d-n+1;
			a=c+1-b;
		}
		cout<<"TERM "<<n<<" IS "<<a<<"/"<<b<<endl;
	}
	return 0;
}