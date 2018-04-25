#include<iostream>
using namespace std;

const int MAX_INT=2147481647;
int N,***mem,**cost;
bool **in;

int f(const int x,const int y,const int z)
{
	const int cod[4][2]={1,0,-1,0,0,1,0,-1};
	if(x==N&&y==N)return cost[N][N];
	if(mem[x][y][z]!=0)return mem[x][y][z];
	in[x][y]=1;
	int i,temp,X,Y,result=MAX_INT;
	for(i=0;i<4;i++)
	{
		X=x+cod[i][0];
		Y=y+cod[i][1];
		if(X>0&&Y>0&&X<=N&&Y<=N&&!in[X][Y])
		{
			temp=f(X,Y,i);
		    if(temp<result)result=temp;
		}
	}
	result+=cost[x][y];
	in[x][y]=0;
	mem[x][y][z]=result;
	return result;
}

int main()
{
	cin>>N;
	int i,j;
	mem=new int**[N+1];
	cost=new int*[N+1];
	in=new bool*[N+1];
	for(i=1;i<=N;i++)
	{
		mem[i]=new int*[N+1];
		cost[i]=new int[N+1];
		in[i]=new bool[N+1];
		for(j=1;j<=N;j++)
		{
			mem[i][j]=new int[4];
			mem[i][j][0]=mem[i][j][1]=mem[i][j][2]=mem[i][j][3]=in[i][j]=0;
			cin>>cost[i][j];
		}
	}
	cout<<f(1,1,0);
	return 0;
}