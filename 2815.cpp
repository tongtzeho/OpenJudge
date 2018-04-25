#include<iostream>
using namespace std;
int e[80][80]={0},w[80][80]={0},n[80][80]={0},s[80][80]={0},mem[80][80]={0},sum=1;
void change(int x,int y)
{
	if(e[x][y]==0&&mem[x][y+1]==0)
	{
		sum++;
		mem[x][y+1]=1;
		change(x,y+1);
	}
	if(w[x][y]==0&&mem[x][y-1]==0)
	{
		sum++;
		mem[x][y-1]=1;
		change(x,y-1);
	}
	if(n[x][y]==0&&mem[x-1][y]==0)
	{
		sum++;
		mem[x-1][y]=1;
		change(x-1,y);
	}
	if(s[x][y]==0&&mem[x+1][y]==0)
	{
		sum++;
		mem[x+1][y]=1;
		change(x+1,y);
	}
	return;
}
void deal(int x,int y,int k)
{
	if(k>=8)
	{
		s[x][y]=1;
		k-=8;
	}
	if(k>=4)
	{
		e[x][y]=1;
		k-=4;
	}
	if(k>=2)
	{
		n[x][y]=1;
		k-=2;
	}
	if(k>=1)
	{
		w[x][y]=1;
		k-=1;
	}
	return;
}
int main()
{
	int i,j,k,p,q,times=0,max=0;
	cin>>p>>q;
	for(i=1;i<=p;i++)
		for(j=1;j<=q;j++)
		{
			cin>>k;
			deal(i,j,k);
		}
	for(i=1;i<=p;i++)
		for(j=1;j<=q;j++)
		{
			if(mem[i][j]==0)times++;
			mem[i][j]=1;
			sum=1;
			change(i,j);
			if(sum>max)max=sum;
		}
	cout<<times<<endl<<max;
	return 0;
}