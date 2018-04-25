#include<iostream>
#include<cstring>
#include<string>
using namespace std;
char c1[200],c2[200],c3[200],c4[200],l2;
bool cp(int a)
{
	int i=a;
	while(c4[i]==c3[i])
		i--;
	if(c4[i]>c3[i])return true;
	return false;
}
void min()
{
	int i,m,n,s,t=0;
	for(i=0;i<l2+2;i++)
	{
		m=c4[i]-48;
		n=c3[i]-48;
		s=m-n-t;
		if(s<0)
		{
			s+=10;
			t=1;
		}
		else t=0;
		c4[i]=s+48;
	}
}
int main()
{
	int result[200]={0},i,j,l,t,l1,n;
	cin>>n;
	for(l=1;l<=n;l++)
	{
		cin>>c1>>c2;
		l1=strlen(c1);
		l2=strlen(c2);
		for(i=0;i<200;i++)
		{
			c3[i]=i<l2?c2[l2-1-i]:'0';
			c4[i]='0';
			result[i]=0;
		}
		for(i=0;i<l1;i++)
		{
			for(j=l2+5;j>=1;j--)
				c4[j]=c4[j-1];
			c4[0]=c1[i];
		    while(cp(l2+2))
			{
			    result[i]++;
			    min();
			}
		}
		t=0;
		for(i=0;i<l1;i++)
		{
			if(result[i]!=0)t=1;
			if(t==1)cout<<result[i];
		}
		if(t==0)cout<<0;
		cout<<endl;
	}
	return 0;
}