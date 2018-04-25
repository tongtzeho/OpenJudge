#include<stdio.h>
#include<cstring>
#include<string>
using namespace std;
class HUGEINT
{
public:
	char str[30000];
	HUGEINT operator *= (const HUGEINT N)
	{
		int i,j,l1=strlen(str),l2=strlen(N.str),m,n,s,t;
		char *st1=new char[l1+2],*st2=new char[l2+2],*st3=new char[l1+l2+4],*st4=new char[l1+l2+4];
		for(i=0;i<l1;i++)
			st1[i]=str[l1-i-1];
		for(i=0;i<l2;i++)
			st2[i]=N.str[l2-i-1];
		st1[l1]=st2[l2]='0';
		for(i=0;i<=l1+l2+3;i++)
			st3[i]=st4[i]='0';
		for(j=0;j<l2;j++)
		{
		    m=st2[j]-48;
		    if(m>0)
			{
			    t=0;
			    for(i=0;i<=l1;i++)
				{
				    n=st1[i]-48;
				    s=m*n+t;
				    t=s/10;
				    s%=10;
				    st4[i+j]=s+48;
				}
			    t=0;
			    for(i=j;i<=j+l1;i++)
				{
				    m=st3[i]-48;
				    n=st4[i]-48;
				    st4[i]='0';
				    s=m+n+t;
				    t=s/10;
				    s%=10;
				    st3[i]=s+48;
				}
			}
		}
		j=t=0;
		for(i=l1+l2;i>=0;i--)
		{
			if(st3[i]!='0')t=1;
			if(t)
			{
				str[j]=st3[i];
				j++;
			}
		}
		return *this;
	}
	HUGEINT & operator --(int)
	{
		int i,j,l=strlen(str);
		for(i=l-1;i>=0;i--)
			if(str[i]!='0')break;
		for(j=i+1;j<=l-1;j++)
			str[j]='\0';
		str[i]--;
		return *this;
	}
	HUGEINT & operator ++(int)
	{
		int i,j,l=strlen(str),t=0;
		for(i=l-1;i>=0;i--)
			if(str[i]=='9')str[i]='0';
			else
			{
				str[i]++;
				t=1;
				break;
			}
		if(!t)
		{
			str[0]='1';
			for(i=1;i<=l;i++)
				str[i]='0';
		}
		return *this;
	}
};
int main()
{
	int i,n;
	HUGEINT h1,h2;
	for(i=0;i<30000;i++)
		h1.str[i]=h2.str[i]='\0';
	h1.str[0]='2';
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("%s\n",h1.str);
		if(i==n)break;
		h2=h1;
		h2--;
		h1*=h2;
		h1++;
	}
	return 0;
}