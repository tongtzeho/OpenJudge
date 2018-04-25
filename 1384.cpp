#include <iostream>
#include <algorithm>
using namespace std;

struct COIN
{
	int p, w;
}coin[605];

bool cmp(const COIN &c1, const COIN &c2)
{
	return (c1.p*1.0/c1.w < c2.p*1.0/c2.w);
}

int answer[2][10050];

int main()
{
	int testcase;
	cin >> testcase;
	while (testcase > 0)
	{
		testcase--;
		int e, f, n, i, j;
		cin >> e >> f >> n;
		for (i = 0; i < n; i++)
		{
			cin >> coin[i].p >> coin[i].w;
		}
		sort(coin, coin+n, cmp);
		for (j = 0; j <= f-e; j++)
			answer[0][j] = answer[1][j] = -1;
		for (j = 0; j <= f-e; j++)
			if (j % coin[n-1].w == 0)
			{
				answer[(n-1)%2][j] = coin[n-1].p*(j/coin[n-1].w);
			}
		for (i = n-2; i >= 0; i--)
			for (j = 0; j <= f-e; j++)
			{
				int put = -1, skip = -1;
				if (j >= coin[i].w && answer[i%2][j-coin[i].w] != -1)
				{
					put = coin[i].p+answer[i%2][j-coin[i].w];
				}
				if (answer[(i+1)%2][j] != -1)
				{
					skip = answer[(i+1)%2][j];
				}
				answer[i%2][j] = put;
				if (skip != -1 && (skip < put || put == -1))
				{
					answer[i%2][j] = skip;
				}
			}
		if (answer[0][f-e] != -1)
		{
			cout << "The minimum amount of money in the piggy-bank is " << answer[0][f-e] << "." << endl;
		}
		else
		{
			cout << "This is impossible." << endl;
		}
	}
	return 0;
}
