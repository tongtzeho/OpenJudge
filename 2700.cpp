#include<iostream>
#include<cstring>
#include<string>
using namespace std;

void change(char *st,const char ch1,const char ch2)
{
	int length=strlen(st),i;
	for(i=0;i<length;i++)
		if(st[i]==ch1)st[i]=ch2;
}

int main()
{
	int i,n;
	char str[50],ch1,ch2;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>str>>ch1>>ch2;
		change(str,ch1,ch2);
		cout<<str<<endl;
	}
	return 0;
}