#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
using namespace std;

long long gcd(const long long a,const long long b)
//__int64 gcd(const __int64 a,const __int64 b)
{
	if(a%b==0)return b;
	if(b%a==0)return a;
	if(a>b)return gcd(a-a/b*b,b);
	return gcd(a,b-b/a*a);
}

int main()
{
	int n,m,i,j,k;
	char ch;
	bool b[60][60]={0};
//	__int64 p[2][120]={0},s,v;
	long long p[2][120]={0},s,v;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
		{
			cin>>ch;
			if(ch=='*')b[i][j]=1;
		}
	p[1][1]=1;
	for(i=1;i<=n+2;i++)
		p[1][1]*=2;
	s=p[1][1];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i*2+2;j++)
			p[(i+1)%2][j]=0;
		for(j=1;j<=i;j++)
		{
			if(b[i][j])
			{
				p[(i+1)%2][j*2-1]+=p[i%2][j*2-1]/2;
				p[(i+1)%2][j*2+1]+=p[i%2][j*2-1]/2;
			}
			else p[(i+1)%2][j*2]+=p[i%2][j*2-1];
		}
		for(j=1;j<=i;j++)
			p[(i+1)%2][j*2+1]+=p[i%2][j*2];
	}
	v=gcd(p[(n+1)%2][m*2+1],s);
//	printf("%I64u/%I64u",p[(n+1)%2][m*2+1]/v,s/v);
	cout<<p[(n+1)%2][m*2+1]/v<<"/"<<s/v;
	return 0;
}