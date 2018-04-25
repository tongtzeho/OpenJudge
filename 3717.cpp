#include<iostream>
using namespace std;
int mem[21][21]={0};
int f(int x,int y)
{
	if(x<=0||y<=0)return 0;
	if(x==1&&y==1)return 1;
	if(mem[x][y]!=0)return mem[x][y];
	mem[x][y]=f(x-1,y)+f(x,y-1);
	return mem[x][y];
}
int main()
{
	int x,y;
	cin>>x>>y;
	cout<<f(x,y);
	return 0;
}