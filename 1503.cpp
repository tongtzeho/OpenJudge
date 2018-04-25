#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class VERYLONGINT
{
public:
	char st[128];
	VERYLONGINT(){};
	VERYLONGINT(const char *str)
	{
		int i;
		for(i=0;i<128;i++)
			st[i]='\0';
		for(i=0;i<strlen(str);i++)
			st[i]=str[i];
	}
	VERYLONGINT & operator += (const VERYLONGINT &N)
	{
		char ch1[128],ch2[128],ch3[128];
		int i,j,m,n,s,t,l1=strlen(st),l2=strlen(N.st);
		for(i=0;i<128;i++)
			ch1[i]=ch2[i]=ch3[i]='0';
		for(i=0;i<l1;i++)
			ch1[i]=st[l1-1-i];
		for(i=0;i<l2;i++)
			ch2[i]=N.st[l2-1-i];
		t=0;
		for(i=0;i<=l1+l2;i++)
		{
			m=ch1[i]-'0';
			n=ch2[i]-'0';
			s=m+n+t;
			t=s/10;
			s%=10;
			ch3[i]=s+'0';
		}
		t=0;
		for(i=0;i<128;i++)
			st[i]='\0';
		j=0;
		for(i=127;i>=0;i--)
		{
			if(ch3[i]!='0')t=1;
			if(t)
			{
				st[j]=ch3[i];
				j++;
			}
		}
		if(!t)st[0]='0';
		return *this;
	}
};

int main()
{
	VERYLONGINT n1="0";
	char str[128];
	while(cin>>str)
	{
		if(strlen(str)==1&&str[0]=='0')
		{
			cout<<n1.st;
			return 0;
		}
		else
		{
			VERYLONGINT temp=str;
			n1+=temp;
		}
	}
}
