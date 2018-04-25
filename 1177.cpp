#include <cstdio>
#include <algorithm>
using namespace std;

struct RECT
{
	int x1, x2, y1, y2;
}rect[5003];

struct NODE
{
	int l, r, length, cover;
}node[160013];

struct EDGE
{
	int y, x1, x2;
	bool low;
}edge[10003];

int rectnum;

void buildtree(int l ,int r, int p)
{
	node[p].l = l;
	node[p].r = r;
	node[p].length = node[p].cover = 0;
	if (r-l > 1)
	{
		buildtree(l, (l+r)/2, p*2);
		buildtree((l+r)/2, r, p*2+1);
	}
}

bool cmp(const EDGE &e1, const EDGE &e2)
{
	if (e1.y == e2.y) return e1.low;
	return e1.y < e2.y;
}

void add(int l, int r, int p)
{
	if (l == node[p].l && r == node[p].r)
	{
		node[p].cover++;
		node[p].length = r-l;
	}
	else
	{
		int mid = (node[p].l+node[p].r)/2;
		if (l < mid) add(l, min(mid, r), p*2);
		if (r > mid) add(max(mid, l), r, p*2+1);
		if (node[p*2].length+node[p*2+1].length > node[p].length)
		{
			node[p].length = node[p*2].length+node[p*2+1].length;
		}
	}
}

void del(int l, int r, int p)
{
	if (l == node[p].l && r == node[p].r)
	{
		node[p].cover--;
	}
	else
	{
		int mid = (node[p].l+node[p].r)/2;
		if (l < mid) del(l, min(mid, r), p*2);
		if (r > mid) del(max(mid, l), r, p*2+1);		
	}
	if (!node[p].cover)
	{
		node[p].length = node[p*2].length+node[p*2+1].length;
	}
}

int main()
{
	int i, answer = 0;
	scanf("%d", &rectnum);
	for (i = 0; i < rectnum; i++)
	{
		scanf("%d %d %d %d", &(rect[i].x1), &(rect[i].y1), &(rect[i].x2), &(rect[i].y2));
	}
	buildtree(-10000, 10000, 1);
	for (i = 0; i < rectnum; i++)
	{
		edge[2*i].y = rect[i].y1;
		edge[2*i+1].y = rect[i].y2;
		edge[2*i+1].x1 = edge[2*i].x1 = rect[i].x1;
		edge[2*i+1].x2 = edge[2*i].x2 = rect[i].x2;
		edge[2*i].low = true;
		edge[2*i+1].low = false;
	}
	sort(edge, edge+2*rectnum, cmp);
	for (i = 0; i < rectnum*2; i++)
	{
		int temp = node[1].length;
		if (edge[i].low)
		{
			add(edge[i].x1, edge[i].x2, 1);
			answer += node[1].length-temp;
		}
		else
		{
			del(edge[i].x1, edge[i].x2, 1);
			answer += temp-node[1].length;
		}
	}
	for (i = 0; i <= 160012; i++)
	{
		node[i].length = node[i].cover = 0;
	}
	for (i = 0; i < rectnum; i++)
	{
		edge[2*i].y = rect[i].x1;
		edge[2*i+1].y = rect[i].x2;
		edge[2*i+1].x1 = edge[2*i].x1 = rect[i].y1;
		edge[2*i+1].x2 = edge[2*i].x2 = rect[i].y2;
		edge[2*i].low = true;
		edge[2*i+1].low = false;
	}
	sort(edge, edge+2*rectnum, cmp);
	for (i = 0; i < rectnum*2; i++)
	{
		int temp = node[1].length;
		if (edge[i].low)
		{
			add(edge[i].x1, edge[i].x2, 1);
			answer += node[1].length-temp;
		}
		else
		{
			del(edge[i].x1, edge[i].x2, 1);
			answer += temp-node[1].length;
		}
	}
	printf("%d", answer);
	return 0;
}
