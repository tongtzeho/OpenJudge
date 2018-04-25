#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int sum[15],a[15],order[15],n,m,s[15],p[15],s1,s2,ss[15],memorder[10][50000][10];
bool next()
{
	int i=n,j,k;
	bool b[15]={0};
	while(order[i-1]>order[i])
	{
		i--;
		if(i==1)return 0;
	}
	i--;
	for(j=1;j<i;j++)
		b[order[j]]=1;
	do
	{
	    order[i]++;
	}
	while(b[order[i]]);
	b[order[i]]=k=1;
	for(j=i+1;j<=n;j++)
	{
		while(b[k])
			k++;
		order[j]=k;
		b[k]=1;
	}
	return 1;
}
int main()
{
	int i,j,k,testdata=0,error1,error2,ans[15],error[15],limit[15];
	limit[1]=1;
	memorder[1][1][1]=1;
	for(n=2;n<=8;n++)
	{
		for(j=1;j<=n;j++)
			order[j]=j;
		k=1;
		i=n;
		while(next())
		{
			k++;
			for(j=1;j<=n;j++)
				memorder[i][k][j]=order[j];
		}
		limit[i]=k;
	}
	while(cin>>n)
	{
		if(n==0)return 0;
		testdata++;
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		scanf("%d",&m);
		for(i=1;i<=m;i++)
			scanf("%d%d",s+i,p+i);
		for(i=1;i<=n;i++)
			order[i]=i;
		error1=error2=2147481647;
		for(i=1;i<=5;i++)
			error[i]=2147481647;
		for(k=1;k<=limit[n];k++)
		{
			for(i=1;i<=n;i++)
				order[i]=memorder[n][k][i];
			if(m==0)
			{
				error1=0;
				break;
			}
			sum[1]=a[order[1]];
			for(i=2;i<=n;i++)
				sum[i]=sum[i-1]+a[order[i]];
			s1=s2=0;
			for(i=1;i<=5;i++)
				ss[i]=0;
			for(i=1;i<=m;i++)
			{
				int z=2147481647;
				for(j=1;j<=n;j++)
					if(abs(sum[j]-p[i])<z)z=abs(sum[j]-p[i]);
				ss[s[i]]+=z;
				s1+=z;
				if(ss[1]>error[1])break;
			}
			bool b=0;
			for(i=1;i<=5;i++)
				if(ss[i]!=error[i])
				{
					if(ss[i]<error[i])b=1;
					break;
				}
			if(b)
			{
				error1=s1;
				for(i=1;i<=5;i++)
					error[i]=ss[i];
				for(i=1;i<=n;i++)
					ans[i]=order[i];
			}
			if(error1==0)break;
		}
		printf("Data set %d\nOrder: ",testdata);
		for(i=1;i<=n;i++)
		{
			printf("%d",a[ans[i]]);
			if(i<n)printf(" ");
			else printf("\n");
		}
		printf("Error: %d\n",error1);
	}
}