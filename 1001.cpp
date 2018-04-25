#include<iostream>
#include<cstring>
#include<string>
using namespace std;
char di[300],result[300];
void calc(int m,int l)
{
	if(m==1)return;
	char p[300],c[300];
	int i,j,k,n,d,t,s;
	for(i=0;i<=299;i++)
		p[i]=c[i]='0';
	for(i=1;i<=5;i++)
	{
		d=di[i]-48;
		if(d>0)
		{
			t=0;
			for(j=1;j<=l;j++)
			{
				n=result[j]-48;
				s=d*n+t;
				t=s/10;
				s%=10;
				c[i+j-1]=s+48;
			}
			t=0;
			for(j=i;j<=i+l+8;j++)
			{
				n=p[j]-48;
				d=c[j]-48;
				c[j]='0';
				s=n+d+t;
				t=s/10;
				s%=10;
				p[j]=s+48;
			}
		}
	}
	for(i=0;i<=l+8;i++)
		result[i]=p[i];
	calc(m-1,l+8);
}
int main()
{
	char input[10];
	int m,i,j,k,wei,pre,t;
	while(cin>>input>>m)
	{
		for(i=0;i<=299;i++)
			di[i]=result[i]='0';
		j=0;
		for(i=5;i>=0;i--)
		{
			if(input[i]!='.')
			{
				j++;
				result[j]=di[j]=input[i];
			}
			else wei=5-i;
		}
		calc(m,8);
		wei*=m;
		pre=1;
		while(result[pre]=='0'&&pre<=wei)
			pre++;
		pre--;
		t=0;
		for(i=8*m;i>0;i--)
		{
			if(result[i]!='0'||i==wei)t=1;
			if(i==wei&&i>pre)cout<<'.';
			if(i>pre&&t==1)cout<<result[i];
		}
		cout<<endl;
	}
	return 0;
}
