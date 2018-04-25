#include<iostream>
using namespace std;
int num[60],memmax[60][60],memmin[60][60];
char sign[60];
int maxnum(int a,int b,int c,int d)
{
	if(a>=b&&a>=c&&a>=d)return a;
	if(b>=a&&b>=c&&b>=d)return b;
	if(c>=a&&c>=b&&c>=d)return c;
	return d;
}
int minnum(int a,int b,int c,int d)
{
	if(a<=b&&a<=c&&a<=d)return a;
	if(b<=a&&b<=c&&b<=d)return b;
	if(c<=a&&c<=b&&c<=d)return c;
	return d;
}
int calcmin(int x,int y);
int calcmax(int x,int y)
{
	if(x==y)return num[x];
	if(memmax[x][y]!=-2147483648)return memmax[x][y];
	int i,j,k,s,t,m,n,p,q,d,o=-2147483648;
	for(i=x;i<y;i++)
	{
		j=calcmax(x,i);
		k=calcmax(i+1,y);
		s=calcmin(x,i);
		t=calcmin(i+1,y);
		m=sign[i]=='x'?j*k:j+k;
		n=sign[i]=='x'?j*t:j+t;
		p=sign[i]=='x'?s*k:s+k;
		q=sign[i]=='x'?s*t:s+t;
		d=maxnum(m,n,p,q);
		if(d>o)o=d;
	}
	memmax[x][y]=o;
	return o;
}
int calcmin(int x,int y)
{
	if(x==y)return num[x];
	if(memmin[x][y]!=2147483647)return memmin[x][y];
	int i,j,k,s,t,m,n,p,q,d,o=2147483647;
	for(i=x;i<y;i++)
	{
		j=calcmax(x,i);
		k=calcmax(i+1,y);
		s=calcmin(x,i);
		t=calcmin(i+1,y);
		m=sign[i]=='x'?j*k:j+k;
		n=sign[i]=='x'?j*t:j+t;
		p=sign[i]=='x'?s*k:s+k;
		q=sign[i]=='x'?s*t:s+t;
		d=minnum(m,n,p,q);
		if(d<o)o=d;
	}
	memmin[x][y]=o;
	return o;
}
int main()
{
	int a[60],i,j,k,n,t,m=-2147483648,s[60]={0};
	char ch[60];
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ch[i-1]>>a[i];
		s[i]=-2147483648;
	}
	ch[n]=ch[0];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			num[j]=0;
			sign[j]='t';
			for(k=1;k<=n;k++)
			{
				memmax[j][k]=-2147483648;
				memmin[j][k]=2147483647;
			}
		}
		k=i;
		t=0;
		for(j=1;j<=n;j++)
		{
			if(k==n+1&&t==0)k=t=1;
			num[j]=a[k];
			sign[j]=ch[k];
			k++;
		}
		s[i]=calcmax(1,n);
		if(s[i]>m)m=s[i];
	}
	cout<<m<<endl;
	t=0;
	for(i=1;i<=n;i++)
	{
		if(s[i]==m)
		{
			if(t==1)cout<<' ';
			else t=1;
			cout<<i;
		}
	}
	return 0;
}