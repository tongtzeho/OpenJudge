#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#define LARGE 20000
using namespace std;

int result[2005] = {0};
int mem[2005] = {0};

int main()
{
	int testcase, i, j, k, n, m;
	scanf("%d", &testcase);
	while (testcase > 0)
	{
		testcase--;
		scanf("%d %d", &m, &n);
		for (i = 0; i <= n; i++)
		{
			result[i] = 0;
			mem[i] = 0;		
		}
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &k);
				if (i == 0)
				{
					result[j] = k;
				}
				else
				{
					mem[j] = k;
				}
			}
			if (i == 0)
			{
				sort(result, result+n);
			}
			else
			{
				sort(mem, mem+n);
				priority_queue<int> q;
				for (j = 0; j < n; j++)
				{
					q.push(result[j]+mem[0]);
				}
				for (j = 1; j < n; j++)
				{
					for (k = 0; k < n; k++)
					{
						if (result[k]+mem[j] < q.top())
						{
							q.pop();
							q.push(result[k]+mem[j]);
						}
						else
						{
							break;
						}
					}
					if (k == 0)
					{
						break;
					}
				}
				for (j = 0; j < n; j++)
				{
					result[n-j-1] = q.top();
					q.pop();
				}
			}
		}
		printf("%d", result[0]);
		for (i = 1; i < n; i++)
		{
			printf(" %d", result[i]);
		}
		printf("\n");
	}
	return 0;
}
