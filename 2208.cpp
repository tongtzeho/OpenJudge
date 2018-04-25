#include<iostream>
#include<cmath>
#include<iomanip>
double volume(double a,double b,double c,double d,double e,double f)
{
	double a1,a2,a3,w,v;
	a1=acos((a*a+b*b-d*d)/(2*a*b));
	a2=acos((a*a+c*c-e*e)/(2*a*c));
	a3=acos((b*b+c*c-f*f)/(2*b*c));
	w=(a1+a2+a3)/2;
	v=a*b*c/3*sqrt(sin(w)*sin(w-a1)*sin(w-a2)*sin(w-a3));
	return v;
}
using namespace std;
int main()
{
	double a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	cout<<setiosflags(ios::fixed)<<setprecision(4)<<volume(a,b,c,d,e,f);
	return 0;
}