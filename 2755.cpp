#include<iostream>
using namespace std;
int mem[50][30],n,a[30];
int f(const int x,const int y)
{
	if(x==0)return 1;
	if(y>n||x<0)return 0;
	if(mem[x][y]!=-1)return mem[x][y];
	mem[x][y]=f(x,y+1)+f(x-a[y],y+1);
	return mem[x][y];
}
int main()
{
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		for(j=0;j<=40;j++)
			mem[j][i]=-1;
	}
	cout<<f(40,1);
	return 0;
}