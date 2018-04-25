#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX_N 10003
using namespace std;
class EDGE
{
public:
	int u,v,l;
	EDGE(const int U,const int V,const int L)
	{
		u=U;
		v=V;
		l=L;
	}
};
vector<EDGE> v[MAX_N];
vector<int> vdis,vdis2;
bool iscalc[MAX_N];
int n,k,answer,father[MAX_N],depth[MAX_N],deepestpoint,deepestval;
inline int max(const int x,const int y)
{
	if(x>y)return x;
	return y;
}
int maxdepth(const int x,const int f,const int dep)
{
	father[x]=f;
	depth[x]=dep;
	if(depth[x]>deepestval)
	{
		deepestval=dep;
		deepestpoint=x;
	}
	int result=0,i,to,tmp;
	for(i=0;i<v[x].size();i++)
	{
		to=v[x][i].v;
		if(to!=f&&!iscalc[to])
		{
			tmp=maxdepth(to,x,dep+1);
			if(tmp+1>result)result=tmp+1;
		}
	}
	return result;
}
int dfsdepth(const int x,const int y,const int z)
{
	int result=0,i,to,tmp;
	for(i=0;i<v[x].size();i++)
	{
		to=v[x][i].v;
		if(to!=y&&to!=z&&!iscalc[to])
		{
			tmp=dfsdepth(to,y,x);
			if(tmp+1>result)result=tmp+1;
		}
	}
	return result;
}
int calcanswer(vector<int> &vt)
{
	sort(vt.begin(),vt.end());
	int i,j=vt.size()-1,result=0;
	for(i=0;i<vt.size();i++)
	{
		while(vt[i]+vt[j]>k)
		{
			j--;
			if(i>=j)break;
		}
		if(i>=j)break;
		result+=j-i;
	}
	return result;
}
void getdis(const int x,const int f,const int d,const int root)
{
	int i,to;
	if(x!=root&&d<=k)answer++;
	for(i=0;i<v[x].size();i++)
	{
		if(x==root)vdis2.clear();
		to=v[x][i].v;
		if(to!=f&&!iscalc[to])
		{
			vdis.push_back(d+v[x][i].l);
			vdis2.push_back(d+v[x][i].l);
			getdis(to,x,d+v[x][i].l,root);
		}
		if(x==root)answer-=calcanswer(vdis2);
	}
	if(x==root)answer+=calcanswer(vdis);
}
int main()
{
	vector<int> vdep,vdepval;
	int i,j,x,y,l,cf,tmp,rootp,mintree;
	while(cin>>n>>k)
	{
		if(n==0&&k==0)return 0;
		for(i=1;i<=n;i++)
		{
			iscalc[i]=0;
			v[i].clear();
		}
		answer=0;
		cf=1;
		for(i=1;i<n;i++)
		{
			scanf("%d %d %d",&x,&y,&l);
			v[x].push_back(EDGE(x,y,l));
			v[y].push_back(EDGE(y,x,l));
		}
		for(i=1;i<=n;i++)
		{
			for( ;cf<=n;cf++)
				if(!iscalc[cf])break;
			deepestval=0;
			deepestpoint=cf;
			maxdepth(cf,-1,0);
			vdep.clear();
			vdepval.clear();
			vdepval.push_back(0);
			tmp=deepestpoint;
			while(tmp!=-1)
			{
				vdep.push_back(tmp);
				tmp=father[tmp];
			}
			for(j=1;j<vdep.size();j++)
			{
				vdepval.push_back(dfsdepth(vdep[j],vdep[j-1],father[vdep[j]]));
			}
			mintree=max(vdep.size(),vdepval.back());
			rootp=cf;
			for(j=vdep.size()-2;j>=0;j--)
			{
				vdepval[j]=max(vdepval[j],vdepval[j+1]+1);
				if(max(j,vdepval[j])<mintree)
				{
					mintree=max(j,vdepval[j]);
					rootp=vdep[j];
				}
			}
			iscalc[rootp]=1;
			vdis.clear();
			vdis2.clear();
			getdis(rootp,-1,0,rootp);
		}
		cout<<answer<<endl;
	}
}