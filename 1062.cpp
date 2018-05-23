#include <iostream>
#include <vector>
#include <algorithm>
#define inf 99999999
using namespace std;

int mem[105][105][105];
int val[105], level[105];
bool visited[105] = {0};
vector<int> item[105], addval[105];
int m, n;

int f(int x, int y, int z)
{
	if (visited[x]) return inf;
	if (mem[x][y][z] != -1) return mem[x][y][z];
	visited[x] = true;
	int result = val[x];
	int i;
	for (i = 0; i < item[x].size(); i++)
	{
		if (y - level[item[x][i]] <= m && level[item[x][i]] - z <= m)
		{
			int tmp = addval[x][i]+f(item[x][i], max(y, level[item[x][i]]), min(z, level[item[x][i]]));
			if (tmp < result) result = tmp;
		}
	}
	mem[x][y][z] = result;
	visited[x] = false;
	return mem[x][y][z];
}

int main()
{
	int i, j, k, p, l, x;
	for (i = 0; i < 105; i++)
	{
		val[i] = 0;
		level[i] = 0;
		for (j = 0; j < 105; j++)
			for (k = 0; k < 105; k++)
			{
				mem[i][j][k] = -1;
			}
	}
	cin >> m >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> p >> l >> x;
		val[i] = p;
		level[i] = l;
		for (j = 1; j <= x; j++)
		{
			cin >> p >> l;
			item[i].push_back(p);
			addval[i].push_back(l);
		}
	}
	cout << f(1, level[1], level[1]);
	return 0;
}