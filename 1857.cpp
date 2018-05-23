#include <iostream>
#include <iomanip>
using namespace std;

int b, l, n;
int w[1005], s[1005];
double mem[1005][1005];

double f(int x, int y, int z)
{
	if (x >= n) 
	{
		if (z == 0) return 0;
		else return 60.0*l/z;
	}
	if (mem[x][y] != -1) return mem[x][y];
	if (z == 0)
	{
		mem[x][y] = min(60.0*l/s[x]+f(x+1, 0, 0), f(x+1, w[x], s[x]));
	}
	else if (y+w[x] <= b)
	{
		mem[x][y] = min(f(x+1, y+w[x], min(z, s[x])), 60.0*l/z+f(x, 0, 0));
	}
	else
	{
		mem[x][y] = 60.0*l/z+f(x, 0, 0);
	}
	return mem[x][y];
}

int main()
{
	int i, j;
	while (cin>>b>>l>>n)
	{
		if (b == 0 && l == 0 && n == 0) break;
		for (i = 0; i < n; i++)
		{
			cin>>w[i]>>s[i];
		}
		for (i = 0; i <= n; i++)
			for (j = 0; j <= b; j++)
			{
				mem[i][j] = -1;
			}
		cout<<setprecision(1)<<std::fixed<<f(0, 0, 0)<<endl;
	}
	return 0;
}