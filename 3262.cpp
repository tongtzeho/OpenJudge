#include<iostream>
using namespace std;

int mem[101][101],a[101][101],n;

inline int maxnum(const int x,const int y,const int z)
{
	if(x>=y&&x>=z)return x;
	else if(y>=x&&y>=z)return y;
	else return z;
}

int f(const int x,const int y)
{
	if(x==n)return a[x][y];
	else if(mem[x][y]!=-1)return mem[x][y];
	else
	{
		mem[x][y]=maxnum(a[x][y],f(x+1,y),f(x+1,y+1));
		return mem[x][y];
	}
}

int main()
{
	int i,j,x,y;
	while(cin>>n)
	{
		if(n==0)return 0;
		for(i=1;i<=n;i++)
			for(j=1;j<=i;j++)
			{
				mem[i][j]=-1;
				cin>>a[i][j];
			}
		cin>>x>>y;
		cout<<f(x,y)<<endl;
	}
}
