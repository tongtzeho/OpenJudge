#include <iostream>
#include <iomanip>
#define inf 99999999

using namespace std;

const int divint[6]={720,120,24,6,2,1};
int pos[6][6]={{0},{0,1,2,4,7,11},{0,3,5,8,12},{0,6,9,13},{0,10,14},{0,15}};
double mem[750][105][16];
int n,m,p,q,x,card[20];

double calc(int x1,int x2,int x3)
{
	if(x1<=0)return 0;
	if(mem[x1][x2][x3]>-inf+20)return mem[x1][x2][x3];
	int a[7]={0},i,j;
	double ans[7];
	bool gameover=1;
	for(i=1;i<=5;i++)
		a[i]=x1%divint[i-1]/divint[i];
	for(i=0;i<7;i++)
		ans[i]=-inf;
	for(i=1;i<=5;i++)
		if(a[i]>a[i+1]&&a[i]>0)
		{
			int tmp=card[pos[i][a[i]]]%13-x3%13;
			if(tmp*tmp==1||tmp*tmp==144)
			{
				gameover=0;
				ans[i]=calc(x1-divint[i],x2,card[pos[i][a[i]]])+p;
			}
		}
	if(x2>0)
	{
		ans[0]=0;
		gameover=0;
		for(i=1;i<=13;i++)
			ans[0]+=calc(x1,x2-1,i);
		ans[0]/=13;
		ans[0]-=q;
	}
	if(gameover)mem[x1][x2][x3]=0;
	else
	{
		for(i=0;i<=5;i++)
			if(ans[i]>mem[x1][x2][x3])mem[x1][x2][x3]=ans[i];
	}
	return mem[x1][x2][x3];
}

int main()
{
	int i,j,k;
	const int x1[6]={0,120,264,414,566,719};
	while(cin>>n>>m)
	{
		if(n==0&&m==0)return 0;
		for(i=0;i<730;i++)
			for(j=0;j<=m+2;j++)
				for(k=0;k<14;k++)
					mem[i][j][k]=-inf;
		for(i=1;i<=n*(n+1)/2;i++)
			cin>>card[i];
		cin>>p>>q>>x;
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<calc(x1[n],m,x)<<endl;
	}
}
