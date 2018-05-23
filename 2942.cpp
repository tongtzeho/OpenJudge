#include<iostream>
using namespace std;
int mem[40]={1,1,2};
int fib(int a)
{
	if(a<=1)return 1;
	if(mem[a]!=0)return mem[a];
	int result;
	result=fib(a-1)+fib(a-2);
	mem[a]=result;
	return result;
}
int main()
{
	int a;
	while(cin>>a)
		cout<<fib(a)<<endl;
	return 0;
}