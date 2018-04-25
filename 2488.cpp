#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
vector<char> vc;
vector<int> vn;
int p,q,move;
bool t,get[30][30];
const int dxdy[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
void dfs(const int r,const int c)
{
	vc.push_back(c+64);
	vn.push_back(r);
	move++;
	get[r][c]=1;
	int i;
	if(move==p*q)
	{
		t=1;
		for(i=0;i<move;i++)
			cout<<vc[i]<<vn[i];
		cout<<endl<<endl;
		return;
	}
	for(i=0;i<8&&!t;i++)
	{
		int x=r+dxdy[i][0],y=c+dxdy[i][1];
		if(x>0&&y>0&&x<=p&&y<=q&&!get[x][y]&&!t)dfs(x,y);
	}
	vc.pop_back();
	vn.pop_back();
	move--;
	get[r][c]=0;
}
int main()
{
	int n,i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>p>>q;
		for(j=1;j<=p;j++)
			for(k=1;k<=q;k++)
				get[j][k]=0;
		cout<<"Scenario #"<<i<<":\n";
		move=t=0;
		vc.clear();
		vn.clear();
		for(j=1;j<=p&&!t;j++)
			for(k=1;k<=q&&!t;k++)
				dfs(j,k);
		if(!t)cout<<"impossible\n\n";
	}
	return 0;
}
