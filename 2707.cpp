#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main( )
{
	int n,i;
	double a,b,c,x1,x2,x3,dt;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		dt=b*b-4*a*c;
		if (dt>0)
		{
			x1=(-b+sqrt(dt))/(2*a);
			x2=(-b-sqrt(dt))/(2*a);
			if (x1==0) cout<<setiosflags(ios::fixed)<<setprecision(5)<<"x1=0.00000;x2="<<x2<<endl;
			else if (x2==0) cout<<setiosflags(ios::fixed)<<setprecision(5)<<"x1="<<x1<<";x2=0.00000"<<endl;
			else cout<<setiosflags(ios::fixed)<<setprecision(5)<<"x1="<<x1<<";x2="<<x2<<endl;
		}
		else if (dt==0)
		{	
			x1=(-b)/(2*a);
		    x2=(-b)/(2*a);
			if (x1==0) cout<<"x1=x2=0.00000";
			else cout<<setiosflags(ios::fixed)<<setprecision(5)<<"x1=x2="<<x1<<endl;
        }
		else if (dt<0)
		{
			x1=(-b)/(2*a);
			x2=(-b)/(2*a);
            x3=sqrt(-dt)/(2*a);
            if (x1==0) cout<<setiosflags(ios::fixed)<<setprecision(5)<<"x1=0.00000+"<<x3<<"i;x2=0.00000-"<<x3<<'i'<<endl;
			else cout<<setiosflags(ios::fixed)<<setprecision(5)<<"x1="<<x1<<'+'<<x3<<"i;x2="<<x2<<'-'<<x3<<'i'<<endl;
		}
	}
	return 0;
}