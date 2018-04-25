#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double x,y,c;
double f(double w)
{
	return(c-sqrt((x*x-w*w)*(y*y-w*w))/(sqrt(x*x-w*w)+sqrt(y*y-w*w)));
}
double min(double x,double y)
{
	if(x<y)return x;
	return y;
}
double max(double x,double y)
{
	if(x>y)return x;
	return y;
}
int main()
{
	double w,b1,b2;
	int i,j;
	cout<<setiosflags(ios::fixed)<<setprecision(3);
	while(cin>>x>>y>>c)
	{
		if(x==y)
		{
			cout<<sqrt(x*x-4*c*c)<<endl;
			continue;
		}
		b1=min(sqrt(x*x-4*c*c),sqrt(y*y-4*c*c));
		b2=min(min(x,y)-0.0001,max(sqrt(x*x-4*c*c),sqrt(y*y-4*c*c)));
		w=(b1+b2)/2;
		while(f(w)>0.0002||f(w)<-0.0002)
		{
			w=(b1+b2)/2.0;
			if(f(w)*f(b2)<=0) b1=w;
			else b2=w;
		}
		cout<<w<<endl;
	}
	return 0;
}