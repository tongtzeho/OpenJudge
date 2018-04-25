#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int mem[101][101][28]={0};
char rude[60][4];
char goal[200];
int n,l;
int f(int x,int y,char ch)
{
	if(mem[x][y][ch-64]!=0&&ch!='S') return mem[x][y][ch-64]%2;
	if(mem[x][y][ch-64]!=0&&ch=='S') return mem[x][y][ch-64];
	if(x==y)
	{
		if(ch==goal[x])return 1;
		else if(ch!='S'&&ch!=goal[x])return 0;
		else if(ch=='S'&&ch!=goal[x])return -1;
	}
	int i,j,k,t=0;
	for(i=1;i<=n;i++)
	{
		if(rude[i][0]==ch)
		{
			for(k=x;k<y;k++)
				if(f(x,k,rude[i][1])==1&&f(k+1,y,rude[i][2])==1)
				{
					t=1;
					break;
				}
			if(t==1)break;
		}
	}
	if(t==1)
	{
		mem[x][y][ch-64]=1;
		return 1;
	}
	if(t==0&&ch!='S')
	{
		mem[x][y][ch-64]=2;
		return 0;
	}
	int p,q,m=50000000;
	for(k=x;k<y;k++)
	{
		p=f(x,k,'S');
		q=f(k+1,y,'S');
		if(p>0&&q>0&&m>p+q)m=p+q;
	}
	if(m==50000000)
	{
		mem[x][y][ch-64]=-1;
		return -1;
	}
	mem[x][y][ch-64]=m;
	return m;
}
int main()
{
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>rude[i];
	cin>>goal;
	l=strlen(goal);
	cout<<f(0,l-1,'S');
	return 0;
}