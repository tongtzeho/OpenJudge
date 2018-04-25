#include<iostream>
using namespace std;
int main()
{
	char str[100],ch;
	int i=0,n=0;
	while(cin.get(ch))
	{
		if(ch=='\n')break;
		str[n]=ch;
		n++;
	}
	for(i=0;i<n;i++)
	{
		if(str[i]>=65&&str[i]<=90)cout<<char(int(str[i])+32);
		else if(str[i]>=97&&str[i]<=122)cout<<char(int(str[i])-32);
		else cout<<str[i];
	}
	return 0;
}