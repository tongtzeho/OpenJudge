#include<iostream>
#include<ctime>
using namespace std;

int n,t[63]={0},ans=17;
time_t t0;

void dfs(int m,int r)
{
	int i,j,d,g=0,m1=0,m2=0;
	for(i=m;i<=m*2;i++)
		m1+=t[i];
	if(r+m1-1>=ans)return;
	for(i=m;i<=59;i++)
		if(t[i]>m2)m2=t[i];
	if(r+m2-1>=ans)return;
	for(i=m*2+1;i<=59;i++)
	{
		if(clock()-t0>450000)return;
		if(r+m1-1>=ans||r+m2-1>=ans)return;
		if(t[i]==0)continue;
		d=i-m;
		if(t[(59-m)/d*d+m]==0)continue;
		g=m;
		bool b=1;
		while(g<=59)
		{
			if(t[g]<=0)
			{
				b=0;
				break;
			}
			g+=d;
		}
		if(b)
		{
			g=m;
			while(g<=59)
			{
				t[g]--;
				g+=d;
			}
			j=m;
			while(t[j]==0)
			{
				j++;
				if(j>59)
				{
					if(r<ans)ans=r;
					break;
				}
			}
			if(j<=59&&t[j]>0)dfs(j,r+1);
			g=m;
			while(g<=59)
			{
				t[g]++;
				g+=d;
			}
		}
	}
}
	

int main()
{
	int i,j,st;
	cin>>n;
	t0=clock();
	for(i=0;i<n;i++)
	{
		cin>>j;
		if(i==0)st=j;
		t[j]++;
	}
	dfs(st,1);
	cout<<ans;
	return 0;
}
