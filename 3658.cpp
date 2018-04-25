#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

class POINT
{
public:
	__int64 x,y;
	POINT(){};
	POINT(const __int64 X,const __int64 Y)
	{
		x=X;
		y=Y;
	}
};
vector<POINT> v;

bool cmp(const POINT &p1,const POINT &p2)
{
	if(p1.x!=p2.x)return p1.x<p2.x;
	else return p1.y<=p2.y;
}

inline __int64 dis(const POINT &p,const __int64 x,const __int64 y)
{
	return (x-p.x)*(x-p.x)+(y-p.y)*(y-p.y);
}

int searchx(const int x,const int st,const int ed)
{
	if(st==ed)return st;
	int mid=(st+ed)/2;
	if(v[mid].x<=x&&x<=v[mid].x+1)return mid;
	else if(v[mid+1].x<=x)return searchx(x,mid+1,ed);
	else return searchx(x,st,mid);
}
int main()
{
	int testcase,n,i,j,k,x,y,p;
	__int64 mindis;
	bool t;
	cin>>testcase;
	for(i=1;i<=testcase;i++)
	{
		cin>>n;
		v.clear();
		for(j=1;j<=n;j++)
		{
			scanf("%d %d",&x,&y);
			v.push_back(POINT(x,y));
		}
		t=1;
		sort(v.begin(),v.end(),cmp);
		for(j=1;j<=n;j++)
		{
			scanf("%d %d",&x,&y);
			if(t)
			{
				mindis=dis(v[0],x,y);
				t=0;
			}
			p=searchx(x,0,v.size()-1);
			for(k=p;k>=0;k--)
			{
				if(dis(v[k],x,y)<mindis)mindis=dis(v[k],x,y);
				if(v[p].x-v[k].x>=mindis)break;
			}
			for(k=p;k<v.size();k++)
			{
				if(dis(v[k],x,y)<mindis)mindis=dis(v[k],x,y);
				if(v[p].x-v[k].x>=mindis)break;
			}
		}
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<sqrt(mindis)<<endl;
	}
	return 0;
}