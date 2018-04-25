#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

class POINT
{
public:
	int x,y;
	POINT(int X,int Y)
	{
		x=X;
		y=Y;
	}
};

bool cmp(const POINT &p1,const POINT &p2)
{
	if(p1.x!=p2.x)return p1.x<p2.x;
	else return p1.y<p2.y;
}

vector<POINT> v1;

int main()
{
	int n,i,j,x,y,ans=0,maxy;
	while(cin>>n)
	{
		if(n==0)return 0;
		v1.clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			v1.push_back(POINT(x,y));
		}
		sort(v1.begin(),v1.end(),cmp);
		ans=0;
		maxy=-2147483648;
		for(i=n-1;i>=0;i--)
		{
			if(v1[i].y>maxy)
			{
				ans++;
				maxy=v1[i].y;
			}
		}
		printf("%d\n",ans);
	}
}