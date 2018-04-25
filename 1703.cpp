#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int root[100005];
int distnode[100005];
int distval[100005];

int getroot(int x)
{
	if (x == root[x]) return x;
	return getroot(root[x]);
}

void mergeroot(int x, int y)
{
	int getrootx = getroot(x);
	int getrooty = getroot(y);
	if (getrootx == getrooty) return;
	int newroot = min(getrootx, getrooty);
	vector<int> v;
	int xx = x;
	v.push_back(xx);
	while (root[xx] != xx)
	{
		xx = root[xx];
		v.push_back(xx);
	}
	int yy = y;
	v.push_back(yy);
	while (root[yy] != yy)
	{
		yy = root[yy];
		v.push_back(yy);
	}
	for (int i = 0; i < v.size(); i++)
	{
		root[v[i]] = newroot;
	}
	if (getrootx == newroot)
	{
		distval[y] += 1+distval[x]%2;
		distnode[y] = distnode[x];
	}
	else
	{
		distval[x] += 1+distval[y]%2;
		distnode[x] = distnode[y];
	}
}

void update(int x)
{
	int node = distnode[x];
	while (distnode[node] != node)
	{
		distval[x] += distval[node]%2;
		node = distnode[node];
	}
	distnode[x] = node;
}

int main()
{
	int t, i, j, k, n, m;
	char c[4];
	scanf("%d", &t);
	while (t > 0)
	{
		t--;
		scanf("%d %d", &n, &m);
		for (i = 1; i <= n; i++)
		{
			root[i] = i;
			distnode[i] = i;
			distval[i] = 0;
		}
		for (i = 0; i < m; i++)
		{
			int a, b;
			scanf("%s %d %d", &c, &a, &b);
			update(a);
			update(b);
			if (c[0] == 'A')
			{
				if (n == 2)
				{
					if (a != b) printf("In different gangs.\n");
					else printf("In the same gang.\n");
				}
				else if (getroot(a) != getroot(b))
				{
					printf("Not sure yet.\n");
				}
				else if (distval[a]%2 == distval[b]%2)
				{
					printf("In the same gang.\n");
				}
				else
				{
					printf("In different gangs.\n");
				}
			}
			else
			{
				mergeroot(a, b);
			}
		}
	}
	return 0;
}
