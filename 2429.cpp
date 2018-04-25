#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<stdio.h>
using namespace std;
int main()
{
//	long long a,b,gcd=0,lcm=0,j,k;
	__int64 a,b,gcd=0,lcm=0,j,k;
	int i,l;
	char chnum[30];
	cin>>chnum;
	k=1;
	l=strlen(chnum);
	for(i=l-1;i>=0;i--)
	{
		gcd+=((chnum[i]-'0')*k);
		k*=10;
	}
	if(gcd==1)
	{
		cout<<chnum<<" ";
		cin>>chnum;
		cout<<chnum;
		return 0;
	}
	cin>>chnum;
	k=1;
	l=strlen(chnum);
	for(i=l-1;i>=0;i--)
	{
		lcm+=((chnum[i]-'0')*k);
		k*=10;
	}
	k=sqrt(lcm/gcd);
	for(j=k+1; ;j++)
		if((lcm/gcd)%j==0)break;
	k=lcm/gcd;
	a=gcd*(k/j);
	b=gcd*j;
	printf("%I64u %I64u",a,b);
//	cout<<a<<" "<<b;
	return 0;
}