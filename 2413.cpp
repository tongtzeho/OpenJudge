#include<iostream>
#include<cstring>
#include<string>
#include<set>
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

class DATA
{
public:
	VERYLONGINT n;
	int id;
	DATA(){};
	DATA(const VERYLONGINT &N,const int id_)
	{
		n=N;
		id=id_;
	}
};

class cmp
{
public:
	bool operator()(const DATA &d1,const DATA &d2)const
	{
		int l1=strlen(d1.n.st),l2=strlen(d2.n.st),i;
		if(l1<l2)return true;
		else if(l2<l1)return false;
		else if(strcmp(d1.n.st,d2.n.st)<0)return true;
		else if(strcmp(d1.n.st,d2.n.st)>0)return false;
		else return d1.id<d2.id;
	}
};

int main()
{
	multiset<DATA,cmp> s;
	multiset<DATA,cmp>::iterator iter,iter1,iter2;
	VERYLONGINT n1="1",n2="2",temp;
	int i=3,j,k;
	char ch1[120],ch2[120];
	s.insert(DATA(n1,1));
	s.insert(DATA(n2,2));
	while(strlen(n1.st)<105)
	{
		n1+=n2;
		temp=n1;
		n1=n2;
		n2=temp;
		s.insert(DATA(temp,i));
		i++;
	}
	while(cin>>ch1>>ch2)
	{
		if(strlen(ch1)==1&&ch1[0]=='0'&&strlen(ch2)==1&&ch2[0]=='0')return 0;
		temp=VERYLONGINT(ch1);
		iter1=iter=s.insert(DATA(temp,0));
		iter1++;
		j=iter1->id;
		s.erase(iter);
		temp=VERYLONGINT(ch2);
		iter2=iter=s.insert(DATA(temp,100000));
		iter2--;
		k=iter2->id;
		s.erase(iter);
		cout<<k-j+1<<endl;
	}
}
