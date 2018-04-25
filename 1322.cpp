#include <iostream>
#include <iomanip>
using namespace std;

double mem[10000][103];

double f(int c, int n, int m)
{
	if (mem[n][m] != -1) return mem[n][m];
	if (n%2 != m%2 || m > c || m > n) return 0;
	if (n == 1 && m == 1) return 1;
	double a1 = 0, a2 = 0;
	if (m > 0)
	{
		a1 = f(c, n-1, m-1)*(c-m+1)/c;
	}
	if (m < c)
	{
		a2 = f(c, n-1, m+1)*(m+1)/c;
	}
	mem[n][m] = a1+a2;
	return mem[n][m];
}

int main()
{
	int c, n, m;
	while (cin >> c)
	{
		if (c == 0) break;
		cin >> n >> m;
		int i, j;
		if (m > c || (n%2) != (m%2) || m > n) cout << "0.000" << endl;
		else if (n == 0 && m == 0) cout << "1.000" << endl;
		else
		{
			if (n >= 10000) n = 9998+n%2;
			for (i = 0; i < 10000; i++)
				for (j = 0; j <= c; j++)
					mem[i][j] = -1;
			double answer = f(c, n, m);
			cout << setiosflags(ios::fixed) << setprecision(3) << answer << endl;
		}
	}
	return 0;
}
