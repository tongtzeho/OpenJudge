#include<iostream>
#include<cstring>
using namespace std;
int num[7]={0},a[7]={0},lim,mem[7]={0};
int maxnum,rp;
void deal(int k,int n)
{
	int s=0,temp[7],i,j,m=1;
	for(i=1;i<=k;i++)
	{
		temp[i]=0;
		for(j=1;j<=num[i];j++)
		{
			temp[i]*=10;
			temp[i]+=a[m];
			m++;
		}
		s+=temp[i];
	}
	if(s==maxnum)rp++;
	if(s>maxnum&&s<=lim)
	{
		for(i=1;i<=n;i++)
			mem[i]=i<=k?temp[i]:-1;
		maxnum=s;
		rp=0;
	}
}
void ss(int n,int i,int k,int s)
{
	int j,q;
	if(s>=n)return;
	if(i==k)
	{
		num[k]=n-s;
		deal(k,n);
		return;
	}
	if(i<k)
	{
		for(j=1;j<=n;j++)
		{
			num[i]=j;
			s=0;
			for(q=1;q<=i;q++)
				s+=num[q];
			ss(n,i+1,k,s);
		}
	}
}
int main()
{
	int i,j,n;
	char c[7];
	while(cin>>lim>>c)
	{
	    maxnum=rp=0;
		n=strlen(c);
		if(lim==0)return 0;
		for(i=1;i<=n;i++)
			a[i]=int(c[i-1]-48);
		for(i=1;i<=n;i++)
		{
		    for(j=1;j<=i;j++)
			    num[j]=0;
		    ss(n,1,i,0);
		}
		if(rp>=1)cout<<"rejected\n";
		else if(maxnum==0)cout<<"error\n";
		else 
		{
			cout<<maxnum;
			for(i=1;i<=n;i++)
				if(mem[i]>=0)cout<<' '<<mem[i];
			cout<<endl;
		}
	}
}