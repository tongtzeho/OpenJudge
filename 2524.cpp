#include <stdio.h>
#include <vector>
using namespace std;

int root[50003];
//int dist[50003];

inline int min(int x, int y)
{
	if (x < y) return x;
	return y;
}

int getroot(int x)
{
	int result;
	if (root[x] != x)
	{
		result = getroot(root[x]);
	//	dist[x] = (dist[x]+dist[root[x]])%2;
		root[x] = result;
		return result;
	}
	return root[x];
}

void merge(int x, int y)
{
	int fx, fy;
	fx = getroot(x);
	fy = getroot(y);
	root[fx] = fy;
//	dist[fx] = (dist[x]+dist[y]+1)%2;
}

int main()
{
	int n, m, casenum = 0;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0) break;
		int i;
		for (i = 1; i <= n; i++)
		{
			root[i] = i;
		//	dist[i] = 0;
		}
		for (i = 0; i < m; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			merge(x, y);
		}
		int answer = 0;
		casenum++;
		for (i = 1; i <= n; i++)
		{
			if (root[i] == i) answer++;
		}
		printf("Case %d: %d\n", casenum, answer);
	}
	return 0;
}
