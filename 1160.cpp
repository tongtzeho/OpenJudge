#include<iostream>
#include<cmath>
#define inf 20000000
using namespace std;
int dis[305][305]={0},mem[305][35]={0},v,memsum[305][305]={0};
inline int minnum(const int x,const int y)
{
	if(x<y)return x;
	return y;
}
int sum(const int x,const int y)
{
	if(memsum[x][y]!=0)return memsum[x][y];
	int i,r=0;
	for(i=x+1;i<y;i++)
		r+=minnum(dis[x][i],dis[i][y]);
	memsum[x][y]=r;
	return r;
}
int f(const int pos,const int p)
{
	if(mem[pos][p]!=0)return mem[pos][p];
	int i,j,s,r=inf;
	if(p!=1)
	{
		s=0;
		for(i=pos+1;i<=v-p+2;i++)
		{
			s=sum(pos,i)+f(i,p-1);
			if(s<r)r=s;
		}
	}
	else
	{
		r=0;
		for(i=pos;i<=v;i++)
			r+=dis[i][pos];
	}
	mem[pos][p]=r;
	return r;
}
int main()
{
	int i,j,p,pos[305]={0},mind=inf,r;
	cin>>v>>p;
	for(i=1;i<=v;i++)
	{
		cin>>pos[i];
		for(j=1;j<=i;j++)
			dis[i][j]=dis[j][i]=pos[i]-pos[j];
	}
	for(i=1;i<=v-p+1;i++)
	{
		r=0;
		for(j=1;j<=i;j++)
			r+=dis[i][j];
		r+=f(i,p);
		if(r<mind)mind=r;
	}
	cout<<mind;
	return 0;
}
