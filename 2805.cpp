#include<stdio.h>
#include<set>
using namespace std;
class POINT
{
public:
	int x,y;
	POINT(){};
	POINT(const int x_,const int y_)
	{
		x=x_;
		y=y_;
	}
};
class cmp
{
public:
	bool operator () (const POINT &p1,const POINT &p2)const
	{
		if(p1.x<p2.x)return true;
		else if(p1.x>p2.x)return false;
		else return p1.y<p2.y;
	}
};
inline POINT f(const POINT &p1,const POINT &p2)
{
	int x1=p1.x,y1=p1.y,x2=p2.x,y2=p2.y,x=x2-x1,y=y2-y1;
	x2=-y,y2=x;
	return POINT(x1+x2,y1+y2);
}
inline POINT g(const POINT &p1,const POINT &p2)
{
	int x1=p1.x,y1=p1.y,x2=p2.x,y2=p2.y,x=x2-x1,y=y2-y1;
	x2=y,y2=-x;
	return POINT(x1+x2,y1+y2);
}
int main()
{
	set<POINT,cmp> s;
	set<POINT,cmp>::iterator it1,it2;
	int i,n,m,x,y;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)return 0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			s.insert(POINT(x,y));
		}
		m=0;
		for(it1=s.begin();it1!=s.end();it1++)
			for(it2=it1;it2!=s.end();it2++)
			{
				if(it1==it2)continue;
				int temp=s.count(f(*it1,*it2))+s.count(g(*it2,*it1));
				if(temp==2)m++;
				temp=s.count(g(*it1,*it2))+s.count(f(*it2,*it1));
				if(temp==2)m++;
			}
		printf("%d\n",m/4);
		s.clear();
	}
}