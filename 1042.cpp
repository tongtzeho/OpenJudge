#include<iostream>
using namespace std;
int main()
{
	bool t2;
	int i,j,k,temp,n,h,f[30],d[30],t[30],ans[30],maxnum[30],a[30][200],s[30][200],b[30],maxpp,minp;
	while(cin>>n)
	{
		if(n==0)return 0;
		cin>>h;
		h*=12;
		maxpp=1;
		for(i=1;i<=n;i++)
			cin>>f[i];
		for(i=1;i<=n;i++)
			cin>>d[i];
		for(i=1;i<n;i++)
			cin>>t[i];
		for(i=0;i<=n;i++)
			maxnum[i]=ans[i]=0;
		for(i=1;i<=n;i++)
			for(j=0;j<h;j++)
			{
				if(f[i]-j*d[i]>0)a[i][j]=f[i]-j*d[i];
				else a[i][j]=0;
				if(j>0)s[i][j]=s[i][j-1]+a[i][j];
				else s[i][j]=a[i][j];
			}
		temp=h;
		for(j=2;j<=n;j++)
			b[j]=0;
		ans[1]=b[1]=temp;
		for(i=1;i<=n;i++)
		{
			if(temp<0)break;
			if(i!=1)
			{
				for(k=1;k<=t[i-1];k++)
				{
					t2=0;
					for(j=1;j<i;j++)
					    if(b[j]>0)
						{
						    if(!t2)minp=j;
						    else if(a[j][b[j]-1]<=a[minp][b[minp]-1])minp=j;
						    t2=1;
						}
					b[minp]--;
				}
			}
			while(i!=1)
			{
				t2=0;
				for(j=1;j<i;j++)
					if(b[j]>0)
					{
						if(!t2)minp=j;
						else if(a[j][b[j]-1]<=a[minp][b[minp]-1])minp=j;
						t2=1;
					}
				if(!t2||a[minp][b[minp]-1]>=a[i][b[i]])break;
				else
				{
					b[minp]--;
					b[i]++;
				}
			}
			for(j=1;j<=i;j++)
				if(b[j]>0)maxnum[i]+=s[j][b[j]-1];
			temp-=t[i];
			if(maxnum[i]>maxnum[maxpp])
			{
				maxpp=i;
				for(j=1;j<=i;j++)
					ans[j]=b[j];
				for(j=i+1;j<=n;j++)
					ans[j]=0;
			}
		}
		for(i=1;i<=n;i++)
		{
			cout<<ans[i]*5;
			if(i<n)cout<<", ";
			else cout<<endl;
		}
		cout<<"Number of fish expected: "<<maxnum[maxpp]<<endl<<endl;
	}
}