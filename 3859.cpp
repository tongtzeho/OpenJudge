#include<iostream>
using namespace std;
int r,c;
const int dxdy[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int total=0,a[102][102]={0};
void bfs(const int x,const int y)
{
	int i,x1,y1;
	a[x][y]=total;
	for(i=0;i<8;i++)
	{
		x1=x+dxdy[i][0];
		y1=y+dxdy[i][1];
		if(x1>0&&y1>0&&x1<=r&&y1<=c&&a[x1][y1]==0)bfs(x1,y1);
	}
}
int main()
{
	cin>>r>>c;
	int i,j;
	char st[102];
	for(i=1;i<=r;i++)
	{
		cin>>st;
		for(j=0;j<c;j++)
			if(st[j]=='.')a[i][j+1]=-1;
	}
	for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)
			if(a[i][j]==0)
			{
				total++;
				bfs(i,j);
			}
	cout<<total;
	return 0;
}
