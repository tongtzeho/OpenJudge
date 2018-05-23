#include<iostream>
using namespace std;
int a[101]={0},n,m,mem[101]={0},s[101]={0},rp[101]={0};
void search(int p,int k,int q,int d,const int r)//从p位置开始 找和为k的 q为必取 分成d组
{
	int i;
	for(i=p;i<=n;i++)
	{
		if(k>=a[i]&&mem[i]==0)
		{
			if(k==a[i])
			{
				if(d==2)
				{
					m=q;
					return;
				}
				mem[i]=1;
				search(1,q,q,d-1,1);
				mem[i]=0;
				return;
			}
			else if(k-a[i]>=a[n]&&k-a[i]<=s[i+1]&&i<n)
			{
				mem[i]=1;
				search(i+1,k-a[i],q,d,2);
				if(m>0)return;
				mem[i]=0;
				if(k==q)return;
			}
		}
	}


}
int main()
{
	int i,j,k,maxnum,sum,l;
	while(cin>>n&&n!=0)
	{
		maxnum=sum=m=0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			sum+=a[i];
			if(a[i]>maxnum)maxnum=a[i];
		}
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				if(a[i]<a[j])
				{
					a[i]^=a[j];
					a[j]^=a[i];
					a[i]^=a[j];
				}
		s[n+1]=0;
		for(i=n;i>=1;i--)
			s[i]=s[i+1]+a[i];
		for(l=sum/maxnum;l>1;l--)
			if(sum%l==0)
			{
			    i=sum/l;
				for(j=1;j<=n+1;j++)
					mem[j]=0;
				search(1,i,i,l,0);
				if(m>0)
				{
					cout<<m<<endl;
					break;
				}
			}
		if(m==0)cout<<sum<<endl;
	}
	return 0;
}