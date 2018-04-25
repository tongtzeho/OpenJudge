#include<iostream>
using namespace std;

int mem[101][101][2];

int f(const int *a,const int x,const int y,const int z)
{
	if(mem[x][y][z]!=-1)return mem[x][y][z];
	if((x>=y)||(z==0&&a[x]>=a[y])||(z==1&&a[x]<=a[y]))return 0;
	int i,m=0;
	if(z==0)
	{
		for(i=x+1;i<y;i++)
			if(a[i]>a[x]&&f(a,i,y,0)>m)m=f(a,i,y,0);
	}
	else
	{
		for(i=y-1;i>x;i--)
			if(a[i]>a[y]&&f(a,x,i,1)>m)m=f(a,x,i,1);
	}
	mem[x][y][z]=m+1;
	return mem[x][y][z];
}

int main()
{
	int n,i,j,k,s,a[101]={0},m=2147481647,p,q;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			mem[i][j][0]=mem[i][j][1]=-1;
	for(i=1;i<=n;i++)
	{
		p=q=0;
		for(j=1;j<i;j++)
			if(f(a,j,i,0)>p)p=f(a,j,i,0);
		for(k=n;k>i;k--)
			if(f(a,i,k,1)>q)q=f(a,i,k,1);
		s=n-1-p-q;
		if(s<m)m=s;
	}
	cout<<m<<endl;
	return 0;
}
