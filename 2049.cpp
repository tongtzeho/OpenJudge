#include<stdio.h>
#include<list>
using namespace std;

class POINT;
class COORDINATE;
class SEA;

class POINT
{
	friend class SEA;
	bool edoor,ego,sdoor,sgo,wdoor,wgo,ndoor,ngo,count;
	POINT()
	{
		edoor=sdoor=wdoor=ndoor=count=0;
		ego=sgo=wgo=ngo=1;
	}
};

class COORDINATE
{
public:
	int x,y;
	COORDINATE(){};
	COORDINATE(const int x_,const int y_)
	{
		x=x_;
		y=y_;
	}
};

class SEA
{
	POINT map[202][202];
	COORDINATE final,max;
	list<COORDINATE> nodoor(const COORDINATE &cod)
	{
		const int dxdy[4][2]={1,0,0,1,-1,0,0,-1};
		int x=cod.x,y=cod.y,i,tempx,tempy;
		const bool goandnodoor[4]={map[x][y].ego&&!map[x][y].edoor,map[x][y].ngo&&!map[x][y].ndoor,map[x][y].wgo&&!map[x][y].wdoor,map[x][y].sgo&&!map[x][y].sdoor};
		list<COORDINATE> lstr;
		map[x][y].count=1;
		for(i=0;i<4;i++)
		{
			tempx=x+dxdy[i][0];
			tempy=y+dxdy[i][1];
			if(tempx>=0&&tempy>=0&&tempx<=max.x&&tempy<=max.y&&!map[tempx][tempy].count&&goandnodoor[i])lstr.push_back(COORDINATE(tempx,tempy));
		}
		return lstr;
	}
	list<COORDINATE> onedoor(const COORDINATE &cod)
	{
		const int dxdy[4][2]={1,0,0,1,-1,0,0,-1};
		int x=cod.x,y=cod.y,i,tempx,tempy;
		const bool door[4]={map[x][y].ego&&map[x][y].edoor,map[x][y].ngo&&map[x][y].ndoor,map[x][y].wgo&&map[x][y].wdoor,map[x][y].sgo&&map[x][y].sdoor};
		list<COORDINATE> lstr;
		for(i=0;i<4;i++)
		{
			tempx=x+dxdy[i][0];
			tempy=y+dxdy[i][1];
			if(tempx>=0&&tempy>=0&&tempx<=max.x&&tempy<=max.y&&!map[tempx][tempy].count&&door[i])lstr.push_back(COORDINATE(tempx,tempy));
		}
		return lstr;
	}
public:
	SEA(const int wallsum,const int doorsum)
	{
		int i,j,x,y,d,l;
		max=COORDINATE(0,0);
		for(i=1;i<=wallsum;i++)
		{
			scanf("%d%d%d%d",&x,&y,&d,&l);
			for(j=1;j<=l;j++)
			{
				if(d==0)
				{
					map[x][y].sgo=map[x][y-1].ngo=0;
					x++;
					if(x>max.x)max.x=x;
				}
				else
				{
					map[x][y].wgo=map[x-1][y].ego=0;
					y++;
					if(y>max.y)max.y=y;
				}
			}
		}
		for(i=1;i<=doorsum;i++)
		{
			scanf("%d%d%d",&x,&y,&d);
			if(d==0)map[x][y].sgo=map[x][y].sdoor=map[x][y-1].ngo=map[x][y-1].ndoor=1;
			else map[x][y].wgo=map[x][y].wdoor=map[x-1][y].ego=map[x-1][y].edoor=1;
			if(x>=max.x)max.x=x+1;
			if(y>=max.y)max.y=y+1;
		}
	}
	int findnemo(const double x,const double y)
	{
		final=COORDINATE(int(x),int(y));
		if(final.x>max.x||final.y>max.y)return 0;
		list<COORDINATE> lst1,lst2,lsttemp;
		list<COORDINATE>::iterator iter,itertemp;
		lst1.push_back(final);
		int r=0;
		while(!map[0][0].count)
		{
			if(lst1.empty())return -1;
			for(iter=lst1.begin();iter!=lst1.end();iter++)
			{
				lsttemp=nodoor(*iter);
				for(itertemp=lsttemp.begin();itertemp!=lsttemp.end();itertemp++)
					lst1.push_back(*itertemp);
			}
			if(map[0][0].count)return r;
			for(iter=lst1.begin();iter!=lst1.end();iter++)
			{
				lsttemp=onedoor(*iter);
				for(itertemp=lsttemp.begin();itertemp!=lsttemp.end();itertemp++)
					lst2.push_back(*itertemp);
			}
			r++;
			lst1.swap(lst2);
			lst2.clear();
		}
	}
};

int main()
{
	int m,n;
	double x,y;
	while(scanf("%d%d",&m,&n))
	{
		if(m<0&&n<0)return 0;
		SEA deepsea(m,n);
		scanf("%lf%lf",&x,&y);
		printf("%d\n",deepsea.findnemo(x,y));
	}
}