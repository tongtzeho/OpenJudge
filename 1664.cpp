#include<iostream>
using namespace std;
int mem[35][30]={0};
int f(int m,int n)
{
	int result=0,i;
	if(mem[m][n]!=0) return mem[m][n];
    else if (m==1||n==1)
	{
		return 1;
	}
	else
	    for(i=m;i>=0;i-=n)
		    result+=f(i,n-1);
	mem[m][n]=result;
	return result;
}
int main()
{
	int i,n,m,t;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>m>>n;
		cout<<f(m,n)<<endl;
	}
	return 0;
}