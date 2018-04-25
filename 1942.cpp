#include<iostream>
using namespace std;

inline unsigned int minnum(const unsigned int x,const unsigned int y)
{
	if(x<y)return x;
	return y;
}

unsigned int C(const unsigned int x,const unsigned int y)
{
	unsigned int j,k;
	double m=1;
	k=minnum(y,x-y);
	for(j=x;j>x-k;j--)
	{
		m*=j;
		m/=(x+1-j);
	}
	return m;
}

int main()
{
	unsigned int x,y;
	while(cin>>x>>y)
	{
		if(x==y&&x==0)return 0;
		cout<<C(x+y,y)<<endl;
	}
}