#include <stdio.h>
#include <algorithm>
using namespace std;

int mem[1003][1003];
int tianji[1003],king[1003],n;

bool cmp(const int &n1,const int &n2)
{
	return n1>n2;
}

inline int max(const int x,const int y)
{
	if(x>y)return x;
	return y;
}

int f(const int x,const int y)
{
	if(y>=n)return 0;
	if(mem[x][y]!=-9999999)return mem[x][y];
	int ret=-99999,u=n-1-y+x;
	if(tianji[u]>king[y])
	{
		ret=1+f(x+1,y+1);
	}
	else if(tianji[u]==king[y])
	{
		if(tianji[x]>king[y])
		{
			ret=max(f(x,y+1),1+f(x+1,y+1));
		}
		else
		{
			ret=max(f(x,y+1),f(x+1,y+1));
		}
	}
	else
	{
		if(tianji[x]>king[y])
		{
			ret=max(f(x,y+1)-1,1+f(x+1,y+1));
		}
		else if(tianji[x]==king[y])
		{
			ret=max(f(x,y+1)-1,f(x+1,y+1));
		}
		else
		{
			ret=f(x,y+1)-1;
		}
	}
	mem[x][y]=ret;
	return ret;
}

int main()
{
	int i,j,ans;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)return 0;
		for(i=0;i<n;i++)
			scanf("%d",tianji+i);
		for(i=0;i<n;i++)
			scanf("%d",king+i);
		sort(tianji,tianji+n,cmp);
		sort(king,king+n,cmp);
		for(i=0;i<=n+1;i++)
			for(j=0;j<=n+1;j++)
				mem[i][j]=-9999999;
		int ans=f(0,0);
		printf("%d\n",ans*200);
	}
}