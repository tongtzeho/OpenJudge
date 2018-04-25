#include <iostream>
#include <string>
using namespace std;

int mem[4003][4003];
string st1, st2;

int max(int x, int y)
{
	if (x>y) return x;
	return y;
}

int f(int x, int y)
{
	if (mem[x][y] != -1) return mem[x][y];
	if (x >= st1.length() || y >= st2.length()) return 0;
	if (st1[x] == st2[y])
	{
		mem[x][y] = 1+f(x+1, y+1);
		return mem[x][y];
	}
	mem[x][y] = max(f(x+1, y), f(x, y+1));
	return mem[x][y];
}

int main()
{
	while (cin >> st1 >> st2)
	{
		int i, j;
		for (i = 0; i <= st1.length(); i++)
			for (j = 0; j <= st2.length(); j++)
				mem[i][j] = -1;
		cout << f(0, 0) << endl;
	}
	return 0;
}
