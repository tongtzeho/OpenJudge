#include<iostream>
using namespace std;
int times=0,limit,m,n[20]={0},d[20]={0},cashmax=0,sum=0,cashnum[20]={0},cashtotal[20]={0};
void change(int t,int a)
{
	sum+=t*d[a];
	cashnum[a]+=t;
	if(sum>cashmax)cashmax=sum;
}
void f(int a,int p)
{
	int i;
	times++;
	if(times>10000000)return;
	change(1,a);
	for(i=a;i<=p;i++)
	{
		if((sum+d[p]>limit)||((sum+cashtotal[i+1]+d[i]*(n[i]-cashnum[i]))<=cashmax))break;
		if(cashnum[i]<n[i]&&((sum+d[i])<=limit)&&((sum+cashtotal[i+1]+d[i]*(n[i]-cashnum[i]))>cashmax))f(i,p);
	}
	change(-1,a);
	return;
}
int main()
{
	int i,j,k,p,t;
	while(cin>>limit>>m)
	{
		cashmax=sum=times=0;
		for(i=0;i<=19;i++)
		{
			n[i]=d[i]=cashnum[i]=cashtotal[i]=0;
			if(i>0&&i<=m)cin>>n[i]>>d[i];
		}
		if(limit*m==0)cout<<"0\n";
		else
		{
		    for(i=1;i<=m;i++)
			    for(j=i+1;j<=m;j++)
				    if(n[i]*d[i]<n[j]*d[j])
					{
					    n[i]^=n[j];
					    n[j]^=n[i];
					    n[i]^=n[j];
					    d[i]^=d[j];
					    d[j]^=d[i];
					    d[i]^=d[j];
					}
		    t=p=0;
		    for(i=m;i>=1;i--)
			{
				if(t==0&&n[i]*d[i]>0)
				{
					p=i;
					t=1;
				}
				if(t==1)
				{
					cashtotal[i]=cashtotal[i+1]+n[i]*d[i];
				}
			}
			for(i=1;i<=p;i++)
			{
		        if(sum+d[p]>limit||sum+cashtotal[i+1]+d[i]*(n[i]-cashnum[i])<=cashmax)break;
        		if(cashnum[i]<n[i]&&sum+d[i]<=limit&&sum+cashtotal[i+1]+d[i]*(n[i]-cashnum[i])>cashmax)f(i,p);
			}
			cout<<cashmax<<endl;
		}
	}
	return 0;
}