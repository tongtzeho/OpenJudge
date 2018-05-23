#include <iostream>
#include <string>
#define NOTFOUND -99999
using namespace std;

const int simi[5][5] = {{5, -1, -2, -1, -3}, {-1, 5, -3, -2, -4}, {-2, -3, 5, -2, -2}, {-1, -2, -2, 5, -1}, {-3, -4, -2, -1, -10}};
int mem[105][105];
int l1, l2;
string str1, str2;

int charid(char c)
{
	if (c == 'A') return 0;
	if (c == 'C') return 1;
	if (c == 'G') return 2;
	if (c == 'T') return 3;
	else return 4;
}

int max(int x, int y)
{
	if (x>y) return x;
	return y;
}

int f(int x, int y)
{
	if (x >= l1 && y >= l2) return 0;
	if (mem[x][y] != NOTFOUND) return mem[x][y];
	int noskip = NOTFOUND;
	int skip1 = NOTFOUND;
	int skip2 = NOTFOUND;
	if (x < l1 && y < l2)
	{
		noskip = simi[charid(str1[x])][charid(str2[y])]+f(x+1, y+1);
	}
	if (y < l2)
	{
		skip1 = simi[4][charid(str2[y])]+f(x, y+1);
	}
	if (x < l1)
	{
		skip2 = simi[charid(str1[x])][4]+f(x+1, y);
	}
	mem[x][y] = max(noskip, max(skip1, skip2));
	return mem[x][y];
}

int main()
{
	int testcase;
	cin>>testcase;
	while (testcase > 0)
	{
		cin>>l1>>str1>>l2>>str2;
		testcase--;
		for (int i = 0; i <= l1; i++)
			for (int j = 0; j <= l2; j++)
			{
				mem[i][j] = NOTFOUND;
			}
		cout<<f(0, 0)<<endl;
	}
	return 0;
}