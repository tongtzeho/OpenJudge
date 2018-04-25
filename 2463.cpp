#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double k,l,s,w,h1,h2,a,b,c,g=9.81,v=10;
	while(cin>>k>>l>>s>>w)
	{
		if(k==0&&l==0&&s==0&&w==0)return 0;
		if(l>=s)
		{
            if(sqrt(2*g*s)>v)cout<<"Killed by the impact.\n";
            else cout<<"James Bond survives.\n";
			continue;
        }
        a=k/2;
		b=-k*l-w*g;
		c=k*l*l/2;
		h1=(-b+sqrt(b*b-4*a*c))/(2*a);
		c+=v*v*w/2;
		h2=(-b+sqrt(b*b-4*a*c))/(2*a);
		if(h2>s)cout<<"Killed by the impact.\n";
		else if(h1<s)cout<<"Stuck in the air.\n";
		else cout<<"James Bond survives.\n";
	}
}