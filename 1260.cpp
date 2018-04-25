#include <stdio.h>
#define inf 99999999

int mem[105][105];
int a[105], p[105], sum[105], c;

int f(int x, int y)
{
	if (mem[x][y] != inf) return mem[x][y];
	if (x >= c)
	{
		if (x == y) return 0;
		else return inf;
	}
	int buy = 0, skip = 0;
	buy = (10+sum[x]-sum[y]+a[x])*p[x]+f(x+1, x+1);
	skip = f(x+1, y);
	if (buy < skip) mem[x][y] = buy;
	else mem[x][y] = skip;
	return mem[x][y];
}

int main()
{
	int testcase;
	scanf("%d", &testcase);
	while (testcase > 0)
	{
		testcase--;
		scanf("%d", &c);
		int i, j;
		for (i = 0; i <= c; i++)
		{
			a[i] = p[i] = sum[i] = 0;
			for (j = 0; j <= c; j++)
			{
				mem[i][j] = inf;
			}
		}
		for (i = 0; i < c; i++)
		{
			scanf("%d %d", a+i, p+i);
			if (i > 0) sum[i] = a[i-1]+sum[i-1];
			else sum[i] = 0;
		}
		printf("%d\n", f(0, 0));
	}
	return 0;
}
