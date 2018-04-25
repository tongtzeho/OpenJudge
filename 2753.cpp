#include<iostream>
using namespace std;
int mem[30]={0,1,1};
int fib(int a)
{
	if(a<=2)return 1;
	if(mem[a]!=0)return mem[a];
	int result;
	result=fib(a-1)+fib(a-2);
	mem[a]=result;
	return result;
}
int main()
{
	int n,a,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		cout<<fib(a)<<endl;
	}
	return 0;
}
