#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char ch[300];
	int i,j=1,n=0;
	cin>>ch;
	for(i=strlen(ch)-1;i>=0;i--)
	{
		n+=(ch[i]-48)*j;
		j*=8;
	}
	cout<<n;
	return 0;
}