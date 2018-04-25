#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a[10]={0},sum[30]={0},tmp,maxans,size,p;
class ORDER
{
public:
	int s,d,n;
	ORDER(int S,int D,int N)
	{
		s=S;
		d=D;
		n=N;
	}
};
vector<ORDER> v;
bool cmp(const ORDER &o1,const ORDER &o2)
{
	return (o1.d-o1.s)*o1.n<(o2.d-o2.s)*o2.n;
}
void dfs(const int id)
{
	if(id>=size)
	{
		if(tmp>maxans)maxans=tmp;
		return;
	}
	bool t=1;
	int i;
	for(i=v[id].s+1;i<=v[id].d;i++)
		if(a[i]+v[id].n>p)
		{
			t=0;
			break;
		}
	if(t)
	{
		for(i=v[id].s+1;i<=v[id].d;i++)
			a[i]+=v[id].n;
		tmp+=(v[id].d-v[id].s)*v[id].n;
		if(tmp+sum[id+1]>maxans)dfs(id+1);
		tmp-=(v[id].d-v[id].s)*v[id].n;
		for(i=v[id].s+1;i<=v[id].d;i++)
			a[i]-=v[id].n;
	}
	if(tmp+sum[id+1]>maxans)dfs(id+1);
}
int main()
{
	int i,j,k,s,d,n,m,o;
	while(cin>>p>>m>>o)
	{
		if(p==0&&m==0&&o==0)return 0;
		v.clear();
		for(i=1;i<=o;i++)
		{
			cin>>s>>d>>n;
			if(n<=p)v.push_back(ORDER(s,d,n));
		}
		sort(v.begin(),v.end(),cmp);
		for(i=1;i<=m;i++)
			a[i]=0;
		tmp=maxans=0;
		size=v.size();
		sum[size]=0;
		for(i=size-1;i>=0;i--)
			sum[i]=sum[i+1]+(v[i].d-v[i].s)*v[i].n;
		dfs(0);
		cout<<maxans<<endl;
	}
}
