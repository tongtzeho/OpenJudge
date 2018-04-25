#include<iostream>
using namespace std;
int g(int x,int b,int c)
{
	int result;
	result=(x+b-b%c+int((x-b%c+0.5)/(c-1)))%b;
	return result;
}
int h(int x,int b,int c)
{
	int result;
	result=(x+c%b)%b;
	return result;
}
int f(int n,int m)
{
	int result=m%2;
    if(n>2)result=n>m?g(f(n-n/m,m),n,m):h(f(n-1,m),n,m);
	return result;
}
int main()
{
	int n,m;
	while(1==1)
	{
		cin>>n>>m;
		if(n==0) break;
		if(m==1) cout<<n<<endl;
		else cout<<f(n,m)+1<<endl;
	}
	return 0;
}