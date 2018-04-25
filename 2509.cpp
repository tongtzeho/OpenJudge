#include<iostream>
using namespace std;
int f(int n,int m,int k)
{
	if(n==0)return 0;
	return n+f((n+m)/k,(n+m)%k,k);
}
int main()
{
	int n,k;
	while(cin>>n>>k)
		cout<<f(n,0,k)<<endl;
	return 0;
}