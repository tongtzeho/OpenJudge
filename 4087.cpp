#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int> q;

int main()
{
	int n, k, i, x, y;
	scanf("%d %d", &n, &k);
	for (i = 0; i < k; i++)
	{
		scanf("%d", &x);
		q.push(x);
	}
	for (i = k; i < n; i++)
	{
		scanf("%d", &x);
		y = q.top();
		if (x < y)
		{
			q.pop();
			q.push(x);
		}
	}
	y = q.top();
	printf("%d\n", y);
	return 0;
}
