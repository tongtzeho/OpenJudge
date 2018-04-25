#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double l,n,c,l2,ans;

void f(const double x1,const double x2)
{
	double mid=(x1+x2)/2;
	if(x2-x1<0.00001)
	{
		ans=mid;
		return;
	}
	double r=mid/2.0+l*l/8.0/mid;
	double l3=2*r*asin(l/2.0/r);
	if(l3<=l2)f(mid,x2);
	else f(x1,mid);
}

int main()
{
	while(cin>>l>>n>>c)
	{
		if(l<0&&n<0&&c<0)return 0;
		l2=(1+n*c)*l;
		f(0,l/2.0);
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<ans<<endl;
	}
}