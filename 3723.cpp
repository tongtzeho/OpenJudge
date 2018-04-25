#include<iostream>
#include<string>
using namespace std;
int a[120][120],n,total[3]={0};
bool b[120][120]={0};
const int dxdy[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
void f(int x,int y,int z)
{
	b[x][y]=1;
	total[z]++;
	int i;
	for(i=0;i<4;i++)
	{
		int x1=x+dxdy[i][0],y1=y+dxdy[i][1];
		if(!b[x1][y1]&&x1>0&&y1>0&&x1<=n&&y1<=n&&(a[x1][y1]==0||a[x1][y1]==z))f(x1,y1,z);
	}
}
int main()
{
	cin>>n;
	string st;
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		cin>>st;
		for(j=0;j<n;j++)
		{
			if(st[j]=='.')a[i][j+1]=0;
			else if(st[j]=='B')a[i][j+1]=1;
			else a[i][j+1]=2;
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][j]!=0&&!b[i][j])f(i,j,a[i][j]);
	cout<<total[1]<<" "<<total[2];
	return 0;
}