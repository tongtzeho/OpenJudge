#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	string st[120];
	int i,j,n;
	n=0;
	while(cin>>st[n])
		n++;
	for(i=0;i<=n-3;i++)
	{
		if(st[i]==st[n-2])st[i]=st[n-1];
		cout<<st[i];
		if(i<n-3)cout<<' ';
	}
	return 0;
}