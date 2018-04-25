#include<iostream>
using namespace std;
int mem[100]={1,2,3,5,8,13,21,34,55,89};
unsigned int fib(int n)
{
	if(mem[n]!=0)return mem[n];
	else mem[n]=fib(n-1)+fib(n-2);
	return mem[n];
}
int main()
{
	int n,i,a,j,max=9;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		cout<<"Scenario #"<<i<<":\n";
		if(a>max)
		{
			for(j=max+1;j<=a;j++)
				fib(j);
			max=a;
		}
		cout<<mem[a]<<endl<<endl;
	}
	return 0;
}