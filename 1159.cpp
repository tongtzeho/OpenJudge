#include<iostream>
#include<cstring>
#include<string>
using namespace std;
short n,**mem;
char *ch;
short f(int x,int y)
{
	if(x<0||y>=n)return 0;
	if(mem[x][y]!=-1)return mem[x][y];
	if(ch[x]==ch[y])
	{
		mem[x][y]=f(x-1,y+1)+1;
		return mem[x][y];
	}
	else
	{
		if(f(x-1,y)>f(x,y+1))mem[x][y]=f(x-1,y);
		else mem[x][y]=f(x,y+1);
		return mem[x][y];
	}
}
int main()
{
	cin>>n;
	ch=new char[n+1];
	cin>>ch;
	mem=new short*[n+1];
	int i,j;
	for(i=0;i<=n;i++)
	{
		mem[i]=new short[n+1];
		for(j=0;j<=n;j++)
		    mem[i][j]=-1;
	}
	int maxnum=0;
	for(i=1;i<=n;i++)
	{
		if(f(i-1,i)*2>maxnum)maxnum=2*mem[i-1][i];
		if(i>1)
			if(f(i-2,i)*2+1>maxnum)maxnum=2*mem[i-2][i]+1;
	}
//	for(i=0;i<n;i++)
//		for(j=i+1;j<=n;j++)
//			cout<<i<<' '<<j<<' '<<f(i,j)<<endl;
	cout<<n-maxnum;
	return 0;
}