#include <stdio.h>
#include <set>
using namespace std;

class POINT
{
public:
	int x,y;
	POINT(int X,int Y)
	{
		x=X;
		y=Y;
	}
};

class cmp
{
public:
	bool operator()(const POINT &p1, const POINT &p2) const
	{
		return p1.x<p2.x||(p1.x==p2.x&&p1.y<p2.y);
	}
};

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n <= 0) break;
		set<POINT, cmp> s;
		int i;
		for (i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			s.insert(POINT(x, y));
		}
		int count = 0;
		set<POINT, cmp>::iterator iter1, iter2, iter3, iter4;
		for (iter1 = s.begin(); iter1 != s.end(); iter1++)
			for (iter2 = iter1; iter2 != s.end(); iter2++)
			{
				POINT p1 = *iter1;
				POINT p2 = *iter2;
				if (p1.x<p2.x&&p1.y<=p2.y)
				{
					int x3 = p2.x-(p2.y-p1.y);
					int y3 = p2.y+(p2.x-p1.x);
					iter3 = s.find(POINT(x3, y3));
					if (iter3 != s.end())
					{
						int x4 = p1.x-(p2.y-p1.y);
						int y4 = p1.y+(p2.x-p1.x);
						iter4 = s.find(POINT(x4, y4));
						if (iter4 != s.end())
						{
							count++;
						}
					}
				}
			}
		printf("%d\n", count);
	}
	return 0;
}