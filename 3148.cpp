#include<iostream>
#include<vector>
#define inf 99999999
using namespace std;
class ROAD
{
public:
	int a,b,c,p,r;
	ROAD(){};
	ROAD(const int A,const int B,const int C,const int P,const int R)
	{
		a=A;
		b=B;
		c=C;
		p=P;
		r=R;
	}
}road[11];
vector<int> v[11];
const int k2[11]={0,1,2,4,8,16,32,64,128,256,512};
int n,m,mem1[11][1025]={0};
bool mem2[11][1025]={0},success=0;
int dfs(const int a,const int t)
{
	if(a==n)
	{
		success=1;
		return 0;
	}
	if(mem1[a][t]==-1&&mem2[a][t])return inf;
	if(mem1[a][t]!=-1)return mem1[a][t];
	mem2[a][t]=1;
	int i,b,c,ans=inf,temp;
	for(i=0;i<v[a].size();i++)
	{
		b=road[v[a][i]].b;
		c=road[v[a][i]].c;
		if((t>>(c-1))&1)temp=road[v[a][i]].p+dfs(b,t|k2[b]);
		else temp=road[v[a][i]].r+dfs(b,t|k2[b]);
		if(temp<ans)ans=temp;
	}
	mem1[a][t]=ans;
	return ans;
}
int main()
{
	int i,j,a,b,c,p,r,ans;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>a>>b>>c>>p>>r;
		v[a].push_back(i);
		road[i]=ROAD(a,b,c,p,r);
	}
	for(i=1;i<=n;i++)
		for(j=0;j<=1024;j++)
			mem1[i][j]=-1;
	ans=dfs(1,1);
	if(success)cout<<ans;
	else cout<<"impossible";
	return 0;
}