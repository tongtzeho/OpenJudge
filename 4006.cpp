#include<iostream>
using namespace std;
int zs[10001]={0},zx[10001]={0},ys[10001]={0},yx[10001]={0},n;
int main()
{
	int i,j,k,tds,x,y;
	cin>>tds>>n;
	k=4*(n-1);
	zs[1]=1;
	i=2;
	while(k>=8)
	{
		zs[i]=zs[i-1]+k;
		k-=8;
		i++;
	}
	j=n-1;
	for(i=1;i<=n/2;i++)
	{
		ys[i]=zs[i]+j;
		yx[i]=ys[i]+j;
		zx[i]=yx[i]+j;
		j-=2;
	}
	for(i=1;i<=tds;i++)
	{
		cin>>x>>y;
		if(n%2==1&&x==y&&x*2-1==n)cout<<n*n<<endl;
		else
		{
			if(x<=n/2)
			{
				if(y<x)k=4;
				else if(y>=x&&x+y<=n)k=1;
				else k=2;
			}
			else
			{
				if(x+y<=n+1)k=4;
				else if(y<=x)k=3;
				else k=2;
			}
			if(k==1)cout<<zs[x]+y-x<<endl;
			else if(k==2)cout<<ys[n+1-y]+x+y-n-1<<endl;
			else if(k==3)cout<<yx[n+1-x]+x-y<<endl;
			else if(k==4)cout<<zx[y]+n+1-x-y<<endl;
		}
	}
	return 0;
}