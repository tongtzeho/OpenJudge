#include<iostream>
using namespace std;
int mem[101][101]={0},a[101][101]={0};
int f(int h,int x/*从上往下*/,int y/*从左往右*/)
{
	if(mem[x][y]!=0)return mem[x][y];
	if(x==h)return a[x][y];
	int i,j;
	i=f(h,x+1,y)+a[x][y];
	j=f(h,x+1,y+1)+a[x][y];
	if(i<j)i=j;
	mem[x][y]=i;
	return i;
}
int main()
{
	int h,i,j;
	cin>>h;
	for(i=1;i<=h;i++)
		for(j=1;j<=i;j++)
			cin>>a[i][j];
	for(i=h-1;i>=1;i--)
		for(j=1;j<=i;j++)
			f(h,i,j);
	cout<<f(h,1,1);
	return 0;
}