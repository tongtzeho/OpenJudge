#include<iostream>
using namespace std;
const int pow2[12]={0,1,3,7,15,31,63,127,255,511,1023};
int way[12][1024][800]={0},waysum[12][1024]={0};
//__int64 mem[12][12][1024]={0};
long long mem[12][12][1024]={0};
//__int64 f(int x,int y,int z)
long long f(int x,int y,int z)
{
	if(mem[x][y][z]!=0)return mem[x][y][z];
	if(y==1)
	{
		if(way[x][z][1]==0)return 1;
		else return 0;
	}
//	__int64 r=0;
	long long r=0;
	int i;
	for(i=1;i<=waysum[x][z];i++)
		r+=f(x,y-1,way[x][z][i]);
	mem[x][y][z]=r;
	return r;
}
int main()
{
	int i,j,k,l,a,b,t,p,q;
	for(i=1;i<=10;i++)
		for(j=0;j<=pow2[i];j++)
		{
			for(k=0;k<=pow2[i];k++)
			{
				a=j&k;
				if(a==0)
				{
					a=j|k;
					t=1;
					p=0;
					for(q=1;q<=i;q++)
					{
						b=a&1;
						if(b==1)
						{
							if(p%2!=0)
							{
								t=0;
								break;
							}
							p=0;
						}
						if(b==0)p++;
						a>>=1;
					}
					if(p%2!=0)t=0;
					if(t==1)
					{
						waysum[i][j]++;
						way[i][j][waysum[i][j]]=k;
					}
				}
			}
		}
	int r,c;
	while(cin>>r>>c&&r!=0)
	{
		if(r>c)
		{
			c^=r;
			r^=c;
			c^=r;
		}
		if(r*c%2==1)cout<<"0\n";
		else cout<<f(r,c,0)<<endl;
	}
	return 0;
}