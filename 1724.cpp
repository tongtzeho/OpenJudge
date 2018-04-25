#include<cstdio>
#include<vector>
#include<list>
#define inf 32700
using namespace std;
class ROAD
{
public:
	char des,l,c;
	ROAD(const int D,const int L,const int C)
	{
		des=D;
		l=L;
		c=C;
	}
};
vector<ROAD> v[101];
int mincost[101][101],minlen[101][101];
int main()
{
	int i,j,k,n,r,s,d,l,c,cost[101],len[101];
	vector<short> v1;
	list<short> lst;
	list<short>::iterator iter,itermin;
	scanf("%d%d%d",&k,&n,&r);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			minlen[i][j]=mincost[i][j]=inf;
	for(i=1;i<=r;i++)
	{
		scanf("%d%d%d%d",&s,&d,&l,&c);
		v[s].push_back(ROAD(d,l,c));
		if(c<mincost[d][s])mincost[d][s]=c;
		if(l<minlen[s][d])minlen[s][d]=l;
	}
	for(i=1;i<n;i++)
	{
		lst.push_back(i);
		cost[i]=inf;
	}
	cost[n]=0;
	v1.push_back(n);
	while(!lst.empty())
	{
		itermin=lst.begin();
		for(iter=lst.begin();iter!=lst.end();iter++)
		{
			s=*iter;
			d=v1.back();
			if(cost[d]+mincost[d][s]<cost[s])cost[s]=cost[d]+mincost[d][s];
			if(cost[s]<cost[*itermin])itermin=iter;
		}
		s=*itermin;
		if(s==inf)break;
		v1.push_back(s);
		lst.erase(itermin);
	}
	v1.clear();
	if(cost[1]>k)
	{
		printf("-1");
		return 0;
	}
	v1.push_back(1);
	lst.clear();
	for(i=2;i<=n;i++)
	{
		lst.push_back(i);
		len[i]=inf;
	}
	int costsum[101]={0};
	bool bj[101]={0,1,0};
	len[1]=0;
	while(!lst.empty())
	{
		s=v1.back();
		for(i=0;i<v[s].size();i++)
		{
			d=v[s][i].des;
			l=v[s][i].l;
			c=v[s][i].c;
			if(!bj[d]&&len[s]+l<=len[d]&&costsum[s]+c+cost[d]<=k)
			{
				len[d]=len[s]+l;
				costsum[d]=costsum[s]+c;
			}
		}
		itermin=lst.begin();
		for(iter=lst.begin();iter!=lst.end();iter++)
		{
			d=*iter;
			if(len[d]<len[*itermin])itermin=iter;
		}
		d=*itermin;
		bj[d]=1;
		v1.push_back(d);
		if(d==n)
		{
			printf("%d",len[n]);
			return 0;
		}
		lst.erase(itermin);
	}
}