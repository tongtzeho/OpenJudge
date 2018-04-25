#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int mem[205][205];
string str1, str2, str3;

int f(int x, int y)
{
	if (mem[x][y] != -1) return mem[x][y];
	if (x == str1.length() && y == str2.length()) return 1;
	else if (x == str1.length())
	{
		if (str2[y] == str3[x+y]) mem[x][y] = f(x, y+1);
		else mem[x][y] = 0;
	}
	else if (y == str2.length())
	{
		if (str1[x] == str3[x+y]) mem[x][y] = f(x+1, y);
		else mem[x][y] = 0;
	}
	else
	{
		if (str1[x] != str3[x+y] && str2[y] != str3[x+y]) mem[x][y] = 0;
		else if (str1[x] == str3[x+y] && str2[y] != str3[x+y]) mem[x][y] = f(x+1, y);
		else if (str1[x] != str3[x+y] && str2[y] == str3[x+y]) mem[x][y] = f(x, y+1);
		else
		{
			mem[x][y] = max(f(x+1, y), f(x, y+1));
		}
	}
	return mem[x][y];
}

int main()
{
	int testcase, i, j, k;
	cin >> testcase;
	for (i = 1; i <= testcase; i++)
	{
		cin >> str1 >> str2 >> str3;
		for (j = 0; j <= str1.length(); j++)
			for (k = 0; k <= str2.length(); k++)
				mem[j][k] = -1;
		if (str1.length() + str2.length() == str3.length()) f(0, 0);
		else mem[0][0] = 0;
		if (mem[0][0]) cout << "Data set " << i << ": yes" << endl;
		else cout << "Data set " << i << ": no" << endl;
	}
	return 0;
}
