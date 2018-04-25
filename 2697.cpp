#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double x;
double f(double a)
{
	return x*x*x+x+a;
}
void solve(double x1,double x2,double b,double a)
{
	x=(x1+x2)/2;
	if(f(a)==0||(x2-x1)<b)return;
	f(a)>0?solve(x1,x,b,a):solve(x,x2,b,a);
}
int main()
{
	int n,i;
	double a,b;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a>>b;
		solve(-a,0,b,a);
		cout<<setiosflags(ios::fixed)<<setprecision(6)<<x<<' '<<f(a)<<endl;
	}
	return 0;
}