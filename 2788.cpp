#include<iostream>
using namespace std;
int f(int x,int y)
{
	if(x==1)return y;
	int r=0,i,t=x;
	for(i=1; ;i*=2)
	{
		if(x*2<=y)
		{
			r+=i;
			x*=2;
			t*=2;
			t++;
		}
		else if(x<=t&&t<=y)
		{
			r+=i;
			return r;
		}
		else if(x<=y)
		{
			r+=y-x+1;
			return r;
		}
		else return r;
	}
}
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		if(a==0&&b==0)return 0;
		cout<<f(a,b)<<endl;
	}
}