#include <stdio.h>
#include <algorithm>
using namespace std;

class ROAD
{
public:
	int v1, v2, length;
};

ROAD road[126000];

bool cmp(const ROAD &r1, const ROAD &r2)
{
	return r1.length < r2.length;
}

int main()
{
	int testcase, n, i, j, k;
	scanf("%d", &testcase);
	for ( ;testcase > 0; testcase--)
	{
		scanf("%d", &n);
		k = 0;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				int length;
				scanf("%d", &length);
				if (j > i)
				{
					road[k].v1 = i;
					road[k].v2 = j;
					road[k].length = length;
					k++;
				}
			}
		}
		sort(road, road+k, cmp);
		int vset[503] = {0};
		int connectnum = 0;
		int setnum = 1;
		k = 0;
		while (true)
		{
			int v1 = road[k].v1;
			int v2 = road[k].v2;
			if (vset[v1] == 0 && vset[v2] == 0)
			{
				vset[v1] = setnum;
				vset[v2] = setnum;
				if (setnum == 1)
				{
					connectnum += 2;
				}
				setnum++;
			}
			else if (vset[v1] == 0 || vset[v2] == 0)
			{
				if (vset[v1] == 0) vset[v1] = vset[v2];
				else vset[v2] = vset[v1];
				if (vset[v1] == 1)
				{
					connectnum++;
				}
			}
			else if (vset[v1] != vset[v2])
			{
				int lesssetnum = vset[v1]<vset[v2]?vset[v1]:vset[v2];
				int biggersetnum = vset[v1]+vset[v2]-lesssetnum;
				for (i = 1; i <= n; i++)
				{
					if (vset[i] == biggersetnum)
					{
						vset[i] = lesssetnum;
						if (lesssetnum == 1)
						{
							connectnum++;
						}
					}
				}
			}
			if (connectnum == n)
			{
				printf("%d\n", road[k].length);
				break;
			}
			k++;
		}
	}
	return 0;
}