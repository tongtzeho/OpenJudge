#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	char st1[500],st2[500],st3[500],st4[500],ch1,ch2,result[500];
	int i,j,k,l,n,m,s,t,p,q;
	cin>>st1>>st2;
	for(i=0;i<=strlen(st1)+strlen(st2);i++)
		st3[i]=st4[i]=result[i]='0';
	for(i=1;i<=strlen(st1);i++)
		st3[i]=st1[strlen(st1)-i];
	for(j=1;j<=strlen(st2);j++)
		st4[j]=st2[strlen(st2)-j];
	t=0;
	for(i=1;i<=strlen(st1)+strlen(st2);i++)
	{
		n=st3[i]-48;
		m=st4[i]-48;
		s=n+m+t;
		t=s/10;
		s%=10;
		result[i]=char(s+48);
	}
	t=0;
	for(i=strlen(st1)+strlen(st2);i>=1;i--)
	{
		if(result[i]!='0')t=1;
		if(t==1)cout<<result[i];
	}
	if(t==0)cout<<0;
	return 0;
}