#include<iostream>
#include<cstring>
#include<string>
#include<list>
using namespace std;
struct POINT
{
	int x,y,n;
	bool t;
}point[25][25],*start,*end,*temp;
int main()
{
	string str;
	int r,c,i,j;
	list<POINT> lst1,lst2;
	list<POINT>::iterator iter;
	const int dxdy[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
	while(cin>>r>>c)
	{
		if(r*c==0)return 0;
		for(i=1;i<=r;i++)
		{
			cin>>str;
			for(j=0;j<c;j++)
			{
				temp=&(point[i][j+1]);
				temp->x=i;
				temp->y=j+1;
				temp->n=0;
				temp->t=str[j]!='#';
				if(str[j]=='@')start=temp;
				else if(str[j]=='*')end=temp;
			}
		}
		lst1.clear();
		lst1.push_back(*start);
		while(!lst1.empty()&&!end->n)
		{
			lst2.clear();
			for(iter=lst1.begin();iter!=lst1.end();iter++)
			{
				int x=iter->x,y=iter->y,tempx,tempy;
				for(i=0;i<4;i++)
				{
					tempx=x+dxdy[i][0];
					tempy=y+dxdy[i][1];
					if(point[tempx][tempy].t&&!point[tempx][tempy].n&&tempx<=r&&tempy<=c&&tempx>0&&tempy>0)
					{
						point[tempx][tempy].n=point[x][y].n+1;
						lst2.push_back(point[tempx][tempy]);
					}
				}
			}
			lst1.swap(lst2);
		}
		if(!end->n)cout<<"-1\n";
		else cout<<(end->n)<<endl;
	}
}