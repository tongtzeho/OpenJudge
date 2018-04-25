#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	char c1[300],c2[300],c3[300],c4[300],times[600],plus[600];
	int i,j,k,s,t,m,n,l1,l2;
	cin>>c3>>c4;
	l1=strlen(c3);
	l2=strlen(c4);
	for(i=0;i<250;i++)
		c1[i]=c2[i]='0';
	for(i=0;i<l1;i++)
		c1[i]=c3[l1-1-i];
	for(i=0;i<l2;i++)
		c2[i]=c4[l2-1-i];
	for(i=0;i<l1+l2+5;i++)
		times[i]=plus[i]='0';
	for(j=0;j<l2;j++)
	{
		m=c2[j]-48;
		if(m>0)
		{
			t=0;
			for(i=0;i<l1+1;i++)
			{
				n=c1[i]-48;
				s=m*n+t;
				t=s/10;
				s%=10;
				times[i+j]=s+48;
			}
			t=0;
			for(i=j;i<j+l1+3;i++)
			{
				m=plus[i]-48;
				n=times[i]-48;
				times[i]='0';
				s=m+n+t;
				t=s/10;
				s%=10;
				plus[i]=s+48;
			}
		}
	}
	t=0;
	for(i=l1+l2+4;i>=0;i--)
	{
		if(plus[i]!='0')t=1;
		if(t==1)cout<<plus[i];
	}
	return 0;
}