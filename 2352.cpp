#include <cstdio>

int notlargerthan[32800] = {0};
int result[15005] = {0};

int query(int x)
{
	int result = 0;
	int temp = 0;
	for (int i = 32768; i != 0; i /= 2)
	{
		if (x >= i)
		{
			temp += i;
			result += notlargerthan[temp];
			x -= i;
		}
		if (x == 0)
		{
			break;
		}
	}
	return result;
}

void insert(int x)
{
	if (x >= 32800) return;
	notlargerthan[x]++;
	int temp1 = x;
	int temp2 = 1;
	while (temp1 % 2 == 0)
	{
		temp1 /= 2;
		temp2 *= 2;
	}
	insert(x+temp2);
}

int main()
{
	int n, i, x, y;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &x, &y);
		int temp = query(x+1);
		insert(x+1);
		result[temp]++;
	}
	for (i = 0; i < n; i++)
	{
		printf("%d\n", result[i]);
	}
	return 0;
}