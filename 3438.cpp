#include <stdio.h>

#define N 50000
#define Q 200000

int height[N+1] = {0};

int max(int a, int b)
{
	return a>b?a:b;
}

int min(int a, int b)
{
	return a<b?a:b;
}

class NODE
{
public:
	int beginindex, endindex, min, max;
	NODE *left, *right, *parent;
	NODE()
	{
		beginindex = endindex = 0;
		min = max = -1;
		left = right = parent = NULL;
	}
	void search(int head, int tail, int &maxans, int &minans)
	{
		if (head == beginindex && tail == endindex)
		{
			maxans = max;
			minans = min;
		}
		else if (right == NULL)
		{
			left -> search(head, tail, maxans, minans);
		}
		else
		{
			if (left -> endindex >= tail)
			{
				left -> search(head, tail, maxans, minans);
			}
			else if (right -> beginindex <= head)
			{
				right -> search(head, tail, maxans, minans);
			}
			else
			{
				int max1, max2, min1, min2;
				left -> search(head, left->endindex, max1, min1);
				right -> search(right->beginindex, tail, max2, min2);
				maxans = max1>max2?max1:max2;
				minans = min1<min2?min1:min2;
			}
		}
	}
};

NODE node[2*N+5];

int main()
{
	int n, q, i;
	scanf("%d%d", &n, &q);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", height+i);
		node[i].beginindex = node[i].endindex = i;
		node[i].max = node[i].min = height[i];
	}
	int head = 1, tail = n;
	while (head < tail)
	{
		int cur = tail;
		int j;
		for (j = head; j <= tail; j+=2)
		{
			cur++;
			if (j != tail)
			{
				node[j].parent = node[j+1].parent = node+cur;
				node[cur].left = node+j;
				node[cur].right = node+j+1;
				node[cur].beginindex = node[j].beginindex;
				node[cur].endindex = node[j+1].endindex;
				node[cur].max = max(node[j].max, node[j+1].max);
				node[cur].min = min(node[j].min, node[j+1].min);
			}
			else
			{
				node[j].parent = node+cur;
				node[cur].left = node+j;
				node[cur].right = NULL;
				node[cur].beginindex = node[j].beginindex;
				node[cur].endindex = node[j].endindex;
				node[cur].max = node[j].max;
				node[cur].min = node[j].min;
			}
		}
		head = tail+1;
		tail = cur;
	}
	for (i = 0; i < q; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int max, min;
		node[tail].search(a, b, max, min);
		printf("%d\n", max-min);
	}
	return 0;
}