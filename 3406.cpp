#include <stdio.h>
#include <algorithm>
using namespace std;

int height[20003];

int main()
{
	int n, b, i;
	scanf("%d%d", &n, &b);
	for (i = 0; i < n; i++)
	{
		scanf("%d", height+i);
	}
	sort(height, height+n);
	int sum = 0;
	for (i = n-1; i >= 0; i--)
	{
		sum += height[i];
		if (sum >= b)
		{
			printf("%d\n", n-i);
			break;
		}
	}
	return 0;
}