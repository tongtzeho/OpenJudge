#include<iostream>
using namespace std;
int main()
{
	int x,y,nx,ny,i,j,k,ax[20]={0},ay[20]={0};
	cin>>x>>y;
	if(x==y)
	{
		cout<<x;
		return 0;
	}
	nx=1;
	while(x>0)
	{
		ax[nx]=x;
		x/=2;
		nx++;
	}
	nx--;
	ny=1;
	while(y>0)
	{
		ay[ny]=y;
		y/=2;
		ny++;
	}
	ny--;
	for(i=nx+ny; ;i--)
		if(ax[i-ny]!=ay[i-nx])
		{
			cout<<ax[i+1-ny];
			return 0;
		}
}