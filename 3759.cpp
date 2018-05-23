#include <iostream>
#include <vector>

using namespace std;

class NUMBER
{
public:
	long long n;
	bool isinfinite;
};

class MATRIX
{
public:
	int size;
	NUMBER mat[300][300];
};

MATRIX mem[24];
MATRIX answer;
MATRIX tmp;
int dis[1003][1003];
bool used[1003]={0};
vector<int> v;

void calc(MATRIX &result,MATRIX &mat1,MATRIX &mat2)
{
	tmp.size=mat1.size;
	int i,j,k;
	for(i=1;i<=tmp.size;i++)
		for(j=i;j<=tmp.size;j++)
		{
			NUMBER ele;
			ele.isinfinite=1;
			for(k=1;k<=tmp.size;k++)
			{
				if(!mat1.mat[i][k].isinfinite&&!mat2.mat[k][j].isinfinite&&(ele.isinfinite||(!ele.isinfinite&&mat1.mat[i][k].n+mat2.mat[k][j].n<ele.n)))
				{
					ele.isinfinite=0;
					ele.n=mat1.mat[i][k].n+mat2.mat[k][j].n;
				}
			}
			tmp.mat[i][j]=ele;
		}
	for(i=1;i<=tmp.size;i++)
		for(j=1;j<i;j++)
			tmp.mat[i][j]=tmp.mat[j][i];
	result=tmp;
}

int main()
{
	int i,j,n,t,s,e,l,p1,p2,si,ei;
	cin>>n>>t>>s>>e;
	for(i=1;i<=1000;i++)
		for(j=1;j<=1000;j++)
			dis[i][j]=-1;
	for(i=1;i<=t;i++)
	{
		cin>>l>>p1>>p2;
		dis[p1][p2]=dis[p2][p1]=l;
		used[p1]=used[p2]=1;
	}
	for(i=1;i<=1000;i++)
	{
		if(used[i])
		{
			v.push_back(i);
			if(i==s)si=v.size();
			if(i==e)ei=v.size();
		}
	}
	mem[1].size=v.size();
	for(i=1;i<=v.size();i++)
		for(j=1;j<=v.size();j++)
		{
			if(dis[v[i-1]][v[j-1]]==-1)mem[1].mat[i][j].isinfinite=1;
			else
			{
				mem[1].mat[i][j].isinfinite=0;
				mem[1].mat[i][j].n=dis[v[i-1]][v[j-1]];
			}
		}
	for(i=2;i<=22;i++)
	{
		calc(mem[i],mem[i-1],mem[i-1]);
	}
	v.clear();
	i=1;
	while(n>0)
	{
		if(n&1)v.push_back(i);
		i++;
		n>>=1;
	}
	answer=mem[v[0]];
	for(i=1;i<v.size();i++)
		calc(answer,answer,mem[v[i]]);
	cout<<answer.mat[si][ei].n<<endl;
	return 0;
}