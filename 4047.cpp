#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
bool b[50001];
int p[50001]={0},dis[50001]={0},num[50001]={0},d[50001]={0},w;
vector<int> v[50001];
void f(const int x)
{
	b[x]=1;
	d[x]=w;
	w++;
	int i;
	for(i=0;i<v[x].size();i++)
		if(!b[v[x][i]])
		{
			f(v[x][i]);
			num[x]+=num[v[x][i]];
			dis[x]+=dis[v[x][i]]+num[v[x][i]];
		}
	w--;
}
void g(const int x)
{
	b[x]=1;
	int i;
	for(i=0;i<v[x].size();i++)
		if(!b[v[x][i]])
		{
			if(x==1)p[v[x][i]]=num[v[x][i]];
			else p[v[x][i]]=p[x]+num[v[x][i]];
			g(v[x][i]);
		}
}
int main()
{
	int testsum,i,j,k,n,I,R,ts,minnum;
	__int64 answer;
//	long long answer;
	scanf("%d",&testsum);
	for(ts=1;ts<=testsum;ts++)
	{
		w=0;
		scanf("%d%d%d",&n,&I,&R);
		for(i=1;i<=n;i++)
		{
			v[i].clear();
			b[i]=d[i]=0;
			dis[i]=p[i]=0;
			num[i]=1;
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&j,&k);
			v[j].push_back(k);
			v[k].push_back(j);
		}
		f(1);
		for(i=1;i<=n;i++)
			b[i]=0;
		g(1);
		minnum=dis[1];
		for(i=2;i<=n;i++)
		{
			dis[i]=dis[1]+n*d[i]-p[i]*2;
			if(dis[i]<minnum)minnum=dis[i];
		}
		answer=I*I*R*minnum;
//		cout<<answer<<endl;
		printf("%I64u\n",answer);
		bool temp=0;
		for(i=1;i<=n;i++)
			if(dis[i]==minnum)
			{
				if(!temp)
				{
					temp=1;
					printf("%d",i);
				}
				else printf(" %d",i);
			}
		printf("\n\n");
	}
	return 0;
}
