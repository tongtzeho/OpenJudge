#include<cstdio>
#include<iostream>
#define MAX_NUM 50003
using namespace std;

int a[MAX_NUM],b[MAX_NUM],suml[MAX_NUM],inl[MAX_NUM],inr[MAX_NUM],tmp[MAX_NUM],n,sum1[MAX_NUM],sum2[MAX_NUM];

void calc(int sum[])
{
	int j,l;
	for(j=1;j<=n;j++)
	{
		if(j==1)
		{
			inl[1]=0;
			inr[1]=1;
			l=0;
		}
		else
		{
			if(inr[j-1]==j-1)
			{
				l=a[j];
				tmp[j]=j-1;
			}
			else
			{
				l+=a[j];
				if(a[j]>suml[j]-suml[tmp[j-1]])tmp[j]=j-1;
				else tmp[j]=tmp[j-1];
			}
			if(l>0)
			{
				l=0;
				inl[j]=inl[j-1];
				inr[j]=j;
			}
			else
			{
				inl[j]=inl[j-1];
				inr[j]=inr[j-1];
			}
			if(suml[j]-suml[tmp[j]]>suml[inr[j]]-suml[inl[j]])
			{
				inl[j]=tmp[j];
				inr[j]=j;
			}
		}
		sum[j]=suml[inr[j]]-suml[inl[j]];
	}
}

int main()
{
	int t,i,j,k,l,ans;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n);
		for(j=0;j<=n;j++)
		{
			a[j]=suml[j]=tmp[j]=0;
			if(j)
			{
				scanf("%d",a+j);
				suml[j]=suml[j-1]+a[j];
			}
		}
		calc(sum1);
		for(j=1;j<=n;j++)
		{
			b[n+1-j]=a[j];
		}
		suml[0]=0;
		for(j=1;j<=n;j++)
		{
			a[j]=b[j];
			suml[j]=suml[j-1]+a[j];
		}
		calc(sum2);
		ans=-2147483648;
		for(j=1;j<n;j++)
			if(sum1[j]+sum2[n-j]>ans)ans=sum1[j]+sum2[n-j];
		cout<<ans<<endl;
	}
	return 0;
}