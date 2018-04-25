#include<iostream>
#include<cmath>
using namespace std;
int max(int x,int y)
{
	if(x>y)return x;
	else return y;
}
int f(int a,int b)
{
	int result=1,i,j;
	if(a<b*b) return 1;
	for(i=b;i*i<=a;i++)
		if(a%i==0) result+=f(a/i,max(b,i));
	return result;
}
int main()
{
	int n,a,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		cout<<f(a,2)<<endl;
	}
	return 0;
}