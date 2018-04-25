#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class COORD
{
public:
	int x,y;
	COORD()
	{
		x=y=0;
	}
	COORD(const char *ch)
	{
		x=ch[0]-'a'+1;
		y=ch[1]-'0';
	}
};

class COORDLIST
{
public:
	int n;
	COORD cod[50];
	COORDLIST(const int n_)
	{
		n=n_;
	}
	COORDLIST()
	{
		n=0;
	}
};

class MAP
{
	COORD start,end;
	int path[9][9];
public:
	COORD init()
	{
		int i,j;
		for(i=1;i<=8;i++)
			for(j=1;j<=8;j++)
				path[i][j]=0;
		char ch1[3],ch2[3];
		if(!(cin>>ch1>>ch2))return COORD("a0");
		cout<<"To get from "<<ch1<<" to "<<ch2<<" takes ";
		start=ch1;
		end=ch2;
		path[start.x][start.y]=1;
		return start;
	}
	void search(const int k,const COORDLIST codlist)
	{
		int i,j,x,y;
		COORDLIST newcodlist;
		const int dxdy[8][2]={1,2,1,-2,2,1,2,-1,-1,2,-1,-2,-2,1,-2,-1};
		if(path[end.x][end.y]!=0)
		{
			cout<<path[end.x][end.y]-1<<" knight moves.\n";
			return;
		}
		for(i=1;i<=codlist.n;i++)
			for(j=0;j<8;j++)
			{
				x=codlist.cod[i].x+dxdy[j][0];
				y=codlist.cod[i].y+dxdy[j][1];
				if(x>0&&y>0&&x<=8&&y<=8&&path[x][y]==0)
				{
					path[x][y]=k+1;
					newcodlist.n++;
					newcodlist.cod[newcodlist.n].x=x;
					newcodlist.cod[newcodlist.n].y=y;
				}
			}
		search(k+1,newcodlist);
	}
}map;

int main()
{
	COORDLIST codlist(1);
	while(1)
	{
		codlist.cod[1]=map.init();
		if(codlist.cod[1].y==0)return 0;
		map.search(1,codlist);
	}
}