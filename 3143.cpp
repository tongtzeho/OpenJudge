#include<iostream>
#include<cmath>
using namespace std;
int main( )
{
	long int n,i,j,k,a,b,c=0,d=0;
	cin>>n;
	if(n<6||n%2==1) 
	{
		cout<<"Error!";
		goto end;
	}
	for (i=3;i<=n/2;i=i+2)
	{
		a=i;b=n-i;c=0;d=0;
		for (j=3;j<=int(sqrt(a));j=j+2)
			if (a%j==0) 
			{
				c=1;
				goto write;
			}
			for (j=3;j<=int(sqrt(b));j=j+2)
			if (b%j==0) 
			{
				d=1;
				goto write;
			}
write:  if (c==0&&d==0) cout<<n<<'='<<a<<'+'<<b<<endl;
	}
end:	return 0;
}