#include<iostream>
#include<cmath>
using namespace std;
int main( )
{
	long int n,i,j,k,a,b,c=0,d=0;
	while(cin>>n&&n!=0){
	for (i=3;i<=n/2;i=i+2)
	{
		a=i;
		b=n-i;
		c=d=0;
		for (j=3;j<=int(sqrt(a));j=j+2)
			if (a%j==0) 
			{
				c=1;
				break;
			}
		for (j=3;j<=int(sqrt(b));j=j+2)
			if (b%j==0) 
			{
				d=1;
				break;
			}
		if(c==0&&d==0)
		{
			cout<<n<<" = "<<a<<" + "<<b<<endl;
			break;
		}
	}
	}
	return 0;
}