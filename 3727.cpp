#include<iostream>
using namespace std;
int mem[120][120]={0},a[120][120]={0},r,c;
int search(int x,int y)
{
	if(x==1||y==1||mem[x][y]!=0)return mem[x][y];
	int m,n;
	m=search(x-1,y)+a[x][y];
	n=search(x,y-1)+a[x][y];
	mem[x][y]=m>n?m:n;
	return mem[x][y];
}
int main()
{
	int t,i,j,k;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>r>>c;
		for(j=0;j<=r+1;j++)
			for(k=0;k<=c+1;k++)
				mem[j][k]=0;
		for(k=1;k<=c;k++)
		{
			cin>>a[1][k];
			mem[1][k]=mem[1][k-1]+a[1][k];
		}
		for(j=2;j<=r;j++)
		{
			cin>>a[j][1];
			mem[j][1]=mem[j-1][1]+a[j][1];
			for(k=2;k<=c;k++)
				cin>>a[j][k];
			search(j,c);
		}
		cout<<mem[r][c]<<endl;
	}
	return 0;
}