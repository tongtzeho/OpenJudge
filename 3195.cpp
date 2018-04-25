#include<iostream>
#include<cmath>
int min(int x,int y)
{
	if(x<y)return x;
	else return y;
}
using namespace std;
int main()
{
	int a,b,i;
	cin>>a>>b;
	{
		if(a%min(a,b)==0&&b%min(a,b)==0) i=min(a,b);
		else
		{
			i=min(a,b)/2;
			while(1==1)
			{
				if(b%i==0&&a%i==0) break;
				i--;
			}
		}
		cout<<dec<<i<<" 0x"<<hex<<i<<" 0"<<oct<<i<<endl;
	}
	return 0;
}
