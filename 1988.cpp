#include <stdio.h>

int root[30010];
int height[30010] = {0};
int offset[30010] = {0};

int getroot(int x)
{
	int result;
	if (x != root[x])
	{
		result = getroot(root[x]);
		offset[x] += offset[root[x]];
		root[x] = result;
		return root[x];
	}
	return root[x];
}

void moveto(int x, int y)
{
	int rx = getroot(x);
	int ry = getroot(y);
	offset[ry] = height[rx]+1;
	height[rx] += 1+height[ry];
	root[ry] = rx;
}

int main()
{
	int p, i, j;
	scanf("%d", &p);
	for (i = 0; i <= 30000; i++)
	{
		root[i] = i;
	}
	while (p > 0)
	{
		p--;
		char c[3];
		scanf("%s", c);
		if (c[0] == 'M')
		{
			int x, y;
			scanf("%d %d", &x, &y);
			moveto(x, y);
		}
		else
		{
			int x;
			scanf("%d", &x);
			getroot(x);
			printf("%d\n", height[root[x]]-offset[x]);
		}
	}
	return 0;
}
