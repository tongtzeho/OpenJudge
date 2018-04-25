#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

#define inf 999999999

using namespace std;

int v,e,mincost=0;
vector<int> road[1003][1003];
int cap[1003][1003]={0};
int flow[1003][1003]={0};

void maxflow_mincost()
{
	list<int> lst;
	bool inlist[1003];
	int i,j,d[1003],prev[1003],flowleft=2;
	while(flowleft>0)
	{
		lst.clear();
		lst.push_back(0);
		for(i=1;i<=v;i++)
			inlist[i]=0;
		inlist[0]=1;
		d[0]=0;
		for(i=1;i<=v;i++)
			d[i]=inf;
		for(i=1;i<=v;i++)
			prev[i]=v+10;
		while(!lst.empty())
		{
			int u=lst.back();
			lst.pop_back();
			inlist[u]=0;
			for(i=1;i<=v;i++)
			{
				if(i!=u&&!road[i][u].empty())
				{
					if(flow[u][i]<0)
					{
						if(d[u]-road[i][u][-flow[u][i]-1]<d[i])
						{
							d[i]=d[u]-road[i][u][-flow[u][i]-1];
							prev[i]=u;
							if(!inlist[i])
							{
								lst.push_front(i);
								inlist[i]=1;
							}
						}
					}
					else
					{
						if(flow[u][i]<cap[u][i]&&d[u]+road[i][u][flow[u][i]]<d[i])
						{
							d[i]=d[u]+road[i][u][flow[u][i]];
							prev[i]=u;
							if(!inlist[i])
							{
								lst.push_front(i);
								inlist[i]=1;
							}
						}
					}
				}
			}
		}
		if(d[v]==inf)return;
		int flownum=2;
		for(i=v;i!=0;i=prev[i])
		{
			if(cap[prev[i]][i]-flow[prev[i]][i]<flownum)flownum=cap[prev[i]][i]-flow[prev[i]][i];
		}
		for(i=v;i!=0;i=prev[i])
		{
			flow[prev[i]][i]+=flownum;
			flow[i][prev[i]]-=flownum;
		}
		mincost+=d[v]*flownum;
		flowleft-=flownum;
	}
}

int main()
{
	int i,j,x,y,dis;
	scanf("%d%d",&v,&e);
	for(i=1;i<=e;i++)
	{
		scanf("%d%d%d",&x,&y,&dis);
		if(x!=y)
		{
			road[x][y].push_back(dis);
			road[y][x].push_back(dis);
			cap[x][y]++;
			cap[y][x]++;
		}
	}
	road[0][1].push_back(0);
	road[0][1].push_back(0);
	road[1][0].push_back(0);
	road[1][0].push_back(0);
	cap[0][1]=cap[1][0]=2;
	for(i=1;i<=v;i++)
		for(j=1;j<=v;j++)
			if(!road[i][j].empty())
			{
				sort(road[i][j].begin(),road[i][j].end());
			}
	maxflow_mincost();
	printf("%d\n",mincost);
	return 0;
}
