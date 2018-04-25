#include <iostream>

using namespace std;

int capacity[203][203]={0};
int flow[203][203]={0};
int e,v;
bool mem[203]={0};

int f(const int x,int y)
{
	if(x==v)return y;
	int ret=0,i;
	mem[x]=1;
	for(i=1;i<=v;i++)
	{
		int dest=i;
		if(!mem[i]&&dest!=x&&flow[x][dest]<capacity[x][dest])
		{
			int nextflow=capacity[x][dest]-flow[x][dest];
			if(nextflow>y)nextflow=y;
			nextflow=f(dest,nextflow);
			y-=nextflow;
			ret+=nextflow;
			flow[x][dest]+=nextflow;
			flow[dest][x]-=nextflow;
		}
	}
	return ret;
}

int main()
{
	int i,j,k,l,capatotal=0,maxflow,ret;
	while(cin>>e>>v)
	{
		for(i=0;i<=v;i++)
		{
			mem[i]=0;
			for(j=0;j<=v;j++)
				capacity[i][j]=flow[i][j]=0;
		}
		maxflow=0;
		for(i=1;i<=e;i++)
		{
			cin>>j>>k>>l;
			capacity[j][k]+=l;
			if(j==1)capatotal+=l;
		}
		while((ret=f(1,capatotal))>0)
		{
			maxflow+=ret;
			for(i=0;i<=v;i++)
				mem[i]=0;
		}
		cout<<maxflow<<endl;
	}
	return 0;
}
