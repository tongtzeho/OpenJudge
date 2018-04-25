#include<iostream>
#include<cmath>
using namespace std;
int n2=0,a1[6]={0,0,9,99,999,9999},a2[6]={0,0,9,189,2889,38889},a4[6]={0,45,9045,1395495,189414495,2147481647};
int solve(int n,int a)
{
	int x0;
	double two,one,zero,x;
	two=a/double(2);
	one=a2[a]-a*(2*a1[a]-1)/double(2);
	zero=a*a1[a]*(a1[a]-1)/double(2)-a2[a]*a1[a]-n;
	x=(-one+sqrt(one*one-4*two*zero))/(2*two);
	if(x-int(x)==0)x0=int(x);
	else x0=int(x)+1;
	n2=-(two*(x0-1)*(x0-1)+one*(x0-1)+zero);
	return x0;
}
int thb(int x,int y)
{
	if(x%y==0)return x/y;
	return x/y+1;
}
int mod(int x,int y)
{
	if(x%y==0)return 0;
	return y-x%y;
}
int main()
{
	int a,b,c,i,j,t,n;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n;
		for(j=1;j<=5;j++)
			if(n<=a4[j])
			{
				a=j;
				break;
			}
		n-=a4[a-1];
		b=solve(n,a);
		for(j=5;j>=1;j--)
			if(n2>a2[j])
			{
				c=j;
				break;
			}
		n2-=a2[c];
		n=thb(n2,c)+a1[c];
		n2=mod(n2,c);
		for(j=1;j<=n2;j++)
			n/=10;
		cout<<n%10<<endl;
	}
	return 0;
}