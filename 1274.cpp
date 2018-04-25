#include <iostream>
using namespace std;

int n,m,ans=0;
int cap[403][403]={0};
int flow[403][403]={0};
bool mem[403]={0};

inline int min(int x,int y)
{
	return x<y?x:y;
}

int maxflow(const int s,int flowleft)
{
	if(s==401)return flowleft;
	mem[s]=1;
	int i,ret=0;
	for(i=0;i<=401;i++)
	{
		if(i!=s&&!mem[i]&&flow[s][i]<cap[s][i])
		{
			int tmp=maxflow(i,min(flowleft,cap[s][i]-flow[s][i]));
			ret+=tmp;
			flow[s][i]+=tmp;
			flow[i][s]-=tmp;
			flowleft-=tmp;
			if(flowleft==0)return ret;
		}
	}
	return ret;
}

int main()
{
	while (cin>>n>>m)
	{
		int i,j;
		for (i=0;i<=401;i++)
			for (j=0;j<=401;j++)
				cap[i][j]=flow[i][j]=0;
		for (i=0;i<=401;i++)
			mem[i]=0;
		ans=0;
		for (i=1;i<=n;i++)
		{
			cap[0][i]=1;
		}
		for (i=1;i<=n;i++)
		{
			int k;
			cin>>k;
			for (j=1;j<=k;j++)
			{
				int l;
				cin>>l;
				cap[i][200+l]=1;
			}
		}
		for (i=1;i<=m;i++)
		{
			cap[200+i][401]=1;
		}
		int fromsource=min(n,m);
		while((j=maxflow(0,fromsource))>0)
		{
			ans+=j;
			for(i=0;i<=401;i++)
				mem[i]=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}
