#include<iostream>
#include<cstring>
#include<string>
using namespace std;
char st[50][5000],st2[5000];
bool cmp(const int x);
void times(const int x);
void times(const int x)
{
	char ch1[5000],ch2[5000],result[5000],temp[5000];
	int i,j,k,l1,l2,s,t,m,n;
	l2=strlen(st[0]);
	for(i=0;i<5000;i++)
		ch1[i]=ch2[i]=result[i]=temp[i]='0';
	for(i=l2-1;i>=0;i--)
		ch2[l2-1-i]=st[0][i];
	l1=strlen(st[x-1]);
	for(i=l1-1;i>=0;i--)
		ch1[l1-1-i]=st[x-1][i];
	s=t=0;
	for(i=0;i<l2;i++)
	{
		m=ch2[i]-'0';
		t=0;
		if(m>0)
		{
		    for(j=0;j<=l1+3;j++)
			{
			    n=ch1[j]-'0';
			    s=m*n+t;
				t=s/10;
				s%=10;
				temp[i+j]=s+'0';
			}
			t=0;
			for(j=i;j<=l1+i+3;j++)
			{
				m=result[j]-'0';
				n=temp[j]-'0';
				temp[j]='0';
				s=m+n+t;
				t=s/10;
				s%=10;
				result[j]=s+'0';
			}
		//	for(j=0;j<l1+l2+3;j++)
		//		cout<<result[j];
		//	cout<<endl;
		}
	}
	j=-1;
	t=0;
	for(i=l1+l2+5;i>=0;i--)
	{
		if(result[i]!='0')
		{
			t=1;
		}
		if(t==1)
		{
			j++;
			st[x][j]=result[i];
	//		cout<<st[x][j];
		}
	}
//	cout<<endl;
}
bool cmp(const int x)
{
	int l1,l2;
	l1=strlen(st[x]);
	l2=strlen(st2);
	if(l1!=l2)
	{
		if(l1>l2)return 0;
		else return 1;
	}
	int i;
	for(i=0;i<l1;i++)
		if(st[x][i]!=st2[i])
		{
			if(st[x][i]>=st2[i])return 0;
			else return 1;
		}
	return 0;
}
int main()
{
	int data,i,j,k;
	cin>>data;
	for(i=1;i<=data;i++)
	{
		for(j=0;j<30;j++)
			for(k=0;k<5000;k++)
				st[j][k]='\0';
		for(k=0;k<5000;k++)
			st2[k]='\0';
		cin>>st[0]>>st2;
		j=0;
		while(cmp(j))
		{
			j++;
			times(j);
		}
		cout<<j<<endl;
	}
	return 0;
}