#include <iostream>
#define inf 999999999
using namespace std;

int m,n,ans=0;
int cap[1103][1103]={0};
int flow[1103][1103]={0};
int firstedge[1003]={0};
bool mem[1103]={0};

inline int min(int x,int y)
{
	if (x<y) return x;
	return y;
}

int maxflow(const int s,int flowleft)
{
	if (s==1101) return flowleft;
	mem[s]=1;
	int i,ret=0;
	if (s == 0)
	{
		for (i=1;i<=m;i++)
		{
			if (flow[s][i]<cap[s][i])
			{
				int tmp=maxflow(i,min(flowleft,cap[s][i]-flow[s][i]));
				ret+=tmp;
				flow[s][i]+=tmp;
				flow[i][s]-=tmp;
				flowleft-=tmp;
				if(flowleft==0)return ret;				
			}
		}
	}
	else if (s >= 1 && s <= m)
	{
		i = firstedge[s];
		if (flow[s][i]<cap[s][i])
		{
			int tmp=maxflow(i,min(flowleft,cap[s][i]-flow[s][i]));
			ret+=tmp;
			flow[s][i]+=tmp;
			flow[i][s]-=tmp;
			flowleft-=tmp;
			if(flowleft==0)return ret;
		}
	}
	else if (s > 1000)
	{
		for (i=1001;i<=1000+n;i++)
		{
			if (i!=s&&!mem[i]&&flow[s][i]<cap[s][i])
			{
				int tmp=maxflow(i,min(flowleft,cap[s][i]-flow[s][i]));
				ret+=tmp;
				flow[s][i]+=tmp;
				flow[i][s]-=tmp;
				flowleft-=tmp;
				if(flowleft==0)return ret;				
			}
		}
		i = 1101;
		if (flow[s][i]<cap[s][i])
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
	cin>>m>>n;
	int i,j,k;
	for (i=1;i<=m;i++)
	{
		cin>>cap[0][i];
	}
	int lastedge[1003]={0};
	int fromsource = 0;
	for (i=1;i<=n;i++)
	{
		int a,b;
		cin>>a;
		for (j=1;j<=a;j++)
		{
			cin>>k;
			if (lastedge[k] == 0)
			{
				firstedge[k] = 1000+i;
				cap[k][1000+i] = inf;
				lastedge[k] = 1000+i;
			}
			else if (lastedge[k] < 1000+i)
			{
				cap[lastedge[k]][1000+i] = inf;
				lastedge[k] = 1000+i;
			}
		}
		cin>>b;
		cap[1000+i][1101] = b;
		fromsource += b;
	}
	while ((j=maxflow(0,fromsource)) > 0)
	{
		ans += j;
		for (i=0;i<=m;i++)
			mem[i] = 0;
		for (i=1001;i<=1000+n;i++)
			mem[i] = 0;
		mem[1101] = 0;
	}
	cout<<ans<<endl;
	return 0;
}
