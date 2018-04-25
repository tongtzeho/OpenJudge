#include<iostream>
using namespace std;

class GOOD
{
public:
	int w,wsum,L,R;
	GOOD()
	{
		w=wsum=L=R=0;
	}
}*good;

int **mem,C,G,*hook,hookL,hookR;

int f(const int x,const int y)
{
	if(y+good[x].L==0||y+good[x].R==0)return 1;
	if(y+good[x].R<0||y+good[x].L>0)return 0;
	if(mem[x][y+good[x].R]!=-1)return mem[x][y+good[x].R];
	int i;
	if(x==1)
	{
		for(i=1;i<=C;i++)
			if(y+good[x].w*hook[i]==0)
			{
				mem[x][y+good[x].R]=1;
				return 1;
			}
		mem[x][y+good[x].R]=0;
		return 0;
	}
	int s=0;
	for(i=1;i<=C;i++)
		s+=f(x-1,y+good[x].w*hook[i]);
	mem[x][y+good[x].R]=s;
	return s;
}

int main()
{
	int i,j,k;
	cin>>C>>G;
	hook=new int[C+1];
	for(i=1;i<=C;i++)
		cin>>hook[i];
	hookL=hook[1];
	hookR=hook[C];
	good=new GOOD[G+1];
	for(i=1;i<=G;i++)
	{
		cin>>good[i].w;
		good[i].wsum=good[i-1].wsum+good[i].w;
		good[i].L=good[i].wsum*hookL;
		good[i].R=good[i].wsum*hookR;
	}
	mem=new int*[G+1];
	for(i=1;i<=G;i++)
	{
		mem[i]=new int[good[i].R-good[i].L+1];
		for(j=0;j<=good[i].R-good[i].L;j++)
			mem[i][j]=-1;
	}
	cout<<f(G,0);
	return 0;
}