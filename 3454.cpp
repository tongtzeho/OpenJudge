#include<cstdio>
#include<vector>
#define MAX_INT 2147483647
using namespace std;

class INTERVAL
{
public:
	__int64 s,e,d;
	INTERVAL(){};
	INTERVAL(__int64 S,__int64 E,__int64 D)
	{
		s=S;
		e=(E-S)/D*D+S;
		d=D;
	}
	__int64 calc_left(__int64 p)
	{
		if(p<s)return 0;
		if(p>e)p=e;
		return (p-s)/d+1;
	}
	__int64 calc_right(__int64 p)
	{
		if(p>=e)return 0;
		return (e-s)/d+1-calc_left(p);
	}
};

vector<INTERVAL> v;
int p,c;

void search(__int64 s,__int64 e)
{
	__int64 size=v.size(),i,ls=0,rs=0,mid=(s+e)/2;
	for(i=0;i<v.size();i++)
	{
		ls+=v[i].calc_left(mid)-v[i].calc_left(s-1);
		rs+=v[i].calc_right(mid)-v[i].calc_right(e);
	}
	if(s==e)
	{
		p=s;
		c=ls;
		return;
	}
	if(ls%2==0&&rs%2==0)return;
	if(ls%2)search(s,mid);
	else search(mid+1,e);
}

int main()
{
	int i,j,n,t,s,e,d,min=MAX_INT,max=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		v.clear();
		p=c=-1;
		for(j=1;j<=t;j++)
		{
			scanf("%d%d%d",&s,&e,&d);
			v.push_back(INTERVAL(s,e,d));
			if(s<min)min=s;
			if(e>max)max=e;
		}
		search(min,max);
		if(p==-1&&c==-1)printf("Poor QIN Teng:(\n");
		else printf("%d %d\n",p,c);
	}
	return 0;
}