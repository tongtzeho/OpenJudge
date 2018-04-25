#include<iostream>
using namespace std;
int main()
{
	int n,k,i,m;
	char f[10];
	cin>>n>>k;
	for(i=1;i<=k;i++)
	{
		cin>>f>>m;
		if(f[1]=='l')n+=m;
		if(f[1]=='i')n-=m;
		if(f[1]=='u')n*=m;
	}
	cout<<n;
	return 0;
}