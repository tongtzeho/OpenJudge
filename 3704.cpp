#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	char ch[150],a[150];
	int i,length,ls,rs;
	while(cin>>ch)
	{
		length=strlen(ch);
		ls=rs=0;
		for(i=0;i<length;i++)
			a[i]=32;
		for(i=0;i<length;i++)
		{
			if(ch[i]=='(')ls++;
			if(ch[i]==')')
			{
				if(rs==ls)a[i]='?';
				if(rs<ls)rs++;
			}
		}
		ls=rs=0;
		for(i=length-1;i>=0;i--)
		{
			if(ch[i]==')')rs++;
			if(ch[i]=='(')
			{
				if(rs==ls)a[i]='$';
				if(ls<rs)ls++;
			}
		}
		for(i=0;i<length;i++)
			cout<<ch[i];
		cout<<endl;
		for(i=0;i<length;i++)
			cout<<a[i];
		cout<<endl;
	}
	return 0;
}