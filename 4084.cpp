#include <iostream>
using namespace std;

class EDGE
{
public:
	int from, to;
}edge[505];

int main()
{
	int v, a, i, j, in[505] = {0};
	cin >> v >> a;
	for (i = 0; i < a; i++)
	{
		cin >> edge[i].from >> edge[i].to;
		in[edge[i].to]++;
	}
	int output = 0;
	for (i = 1; i <= v; i++)
	{
		int ans = -1;
		for (j = 1; j <= v; j++)
		{
			if (in[j] == 0)
			{
				ans = j;
				break;
			}
		}
		if (i == 1) cout << "v" << ans;
		else cout << " v" << ans;
		in[ans] = -1;
		for (j = 0; j < a; j++)
		{
			if (ans == edge[j].from)
			{
				in[edge[j].to]--;
			}
		}
	}
	return 0;
}
