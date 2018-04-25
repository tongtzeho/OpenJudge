#include<iostream>
#include<string>
#include<cstring>
using namespace std;
char chw[40],chn[40];
int length;
void turnnumtoword()
{
	int n[40]={0},i,j,k,l,m=1;
	char st1[40],st2[40];
	for(i=0;i<40;i++)
		st1[i]=st2[i]='\0';
	for(i=0;i<length;i++)
		st1[i]=chn[i];
	while(1)
	{
		k=0;
		l=strlen(st1);
		for(i=0;i<l;i++)
		{
			k*=10;
			k+=st1[i]-'0';
			st2[i]=k/26+'0';
			k%=26;
		}
		for(i=0;i<40;i++)
			st1[i]='\0';
		bool t=0;
		for(i=0;i<l;i++)
		{
			if(st2[i]!='0'&&!t)
			{
				t=1;
				j=i;
			}
			if(t)st1[i-j]=st2[i];
		}
		if(k==0)
		{
			k=26;
			l=strlen(st1);
			for(i=l-1;i>=0;i--)
				if(st1[i]!='0')break;
			st1[i]--;
			for(j=i+1;j<l;j++)
				st1[j]='9';
		}
		n[m]=k;
		m++;
		if(!t)break;
	}
	for(i=1;i<m;i++)
		chw[i-1]=n[m-i]+'a'-1;
}
void turnwordtonum()
{
	char c26[40],tr[40],sum[40];
	int i,j,k,m,n,s,t,t2,l1,l2;
	for(i=0;i<40;i++)
		c26[i]=tr[i]=sum[i]='0';
	c26[0]='1';
	for(i=length-1;i>=0;i--)
	{
		char ct[10];
		for(j=0;j<10;j++)
			ct[j]='0';
		n=chw[i]-'a'+1;
		if(n<=9)
		{
			ct[0]=n+'0';
			l2=1;
		}
		else
		{
			ct[0]=n%10+'0';
			ct[1]=n/10+'0';
			l2=2;
		}
		for(j=0;j<40;j++)
			tr[j]='0';
		for(l1=39;l1>=0;l1--)
			if(c26[l1]!='0')break;
		l1++;
		for(j=0;j<l2;j++)
		{
			n=ct[j]-'0';
			t2=t=0;
			for(k=0;k<=l1+1;k++)
			{
				m=c26[k]-'0';
				s=m*n+t2;
				t2=s/10;
				s%=10;
				s+=t+tr[k+j]-'0';
				t=s/10;
				s%=10;
				tr[k+j]=s+'0';
			}
		}
		t=0;
		for(j=0;j<=l1+3;j++)
		{
			m=sum[j]-'0';
			n=tr[j]-'0';
			s=m+n+t;
			t=s/10;
			s%=10;
			sum[j]=s+'0';
		}
		ct[0]='6';
		ct[1]='2';
		l2=2;
		for(j=0;j<40;j++)
			tr[j]='0';
		for(j=0;j<l2;j++)
		{
			n=ct[j]-'0';
			t2=t=0;
			for(k=0;k<=l1+1;k++)
			{
				m=c26[k]-'0';
				s=m*n+t2;
				t2=s/10;
				s%=10;
				s+=t+tr[k+j]-'0';
				t=s/10;
				s%=10;
				tr[k+j]=s+'0';
			}
		}
		for(j=0;j<40;j++)
			c26[j]=tr[j];
	}
	for(i=39;i>=0;i--)
		if(sum[i]!='0')break;
	for(j=0;j<=i;j++)
		chn[j]=sum[i-j];
}
void output()
{
	int l1=strlen(chw),l2=strlen(chn),i,j;
	cout<<chw;
	for(i=1;i<=22-l1;i++)
		cout<<" ";
	for(i=0;i<l2;i++)
	{
		cout<<chn[i];
		if((l2-i)%3==1&&l2-i>1)cout<<",";
	}
	cout<<endl;
}
int main()
{
	string str;
	int i,j,k;
	while(cin>>str)
	{
		if(str[0]=='*')return 0;
		for(i=0;i<40;i++)
			chw[i]=chn[i]='\0';
		length=str.length();
		if(str[0]>='0'&&str[0]<='9')
		{
			for(i=0;i<str.length();i++)
				chn[i]=str[i];
			turnnumtoword();
		}
		else
		{
			for(i=0;i<str.length();i++)
				chw[i]=str[i];
			turnwordtonum();
		}
		output();
	}
}
