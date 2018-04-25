#include<iostream>
using namespace std;
int mem4[34]={4};
int mem2[34]={2};
int m4(int n)
{
	int i=0,j=1,r=1;
	while(j>0)
	{
		if(n&j)r=r*mem4[i]%10007;
		j<<=1;
		i++;
	}
	return r;
}
int m2(int n)
{
	int i=0,j=1,r=1;
	while(j>0)
	{
		if(n&j)r=r*mem2[i]%10007;
		j<<=1;
		i++;
	}
	return r;
}
int f(int n)
{
	return (m4(n-1)+m2(n-1))%10007;
}
int main()
{
	int t,n,i;
	for(i=1;i<=32;i++)
	{
		mem4[i]=mem4[i-1]*mem4[i-1]%10007;
		mem2[i]=mem2[i-1]*mem2[i-1]%10007;
	}
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n;
		cout<<f(n)<<endl;
	}
	return 0;
}