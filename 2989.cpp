#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int result[6543211];

void trans(int oldpoint, int *newpoint)
{
	const bool move[7][7] 
  ={{0, 0, 1, 0, 1, 0, 1},
	{0, 0, 1, 0, 0, 0, 1},
	{1, 1, 0, 1, 0, 0, 0},
	{0, 0, 1, 0, 1, 0, 0},
	{1, 0, 0, 1, 0, 1, 0},
	{0, 0, 0, 0, 1, 0, 1},
	{1, 1, 0, 0, 0, 1, 0}};
	int olddigit[7] = {oldpoint/1000000, oldpoint/100000%10, oldpoint/10000%10, oldpoint/1000%10, oldpoint/100%10, oldpoint/10%10, oldpoint%10};
	int zero, i;
	for (i = 0; i < 7; i++)
	{
		if (olddigit[i] == 0)
		{
			zero = i;
			break;
		}
	}
	int j, k = 0;
	for (j = 0; j < 7; j++)
	{
		if (move[zero][j])
		{
			int newdigit[7] = {olddigit[0], olddigit[1], olddigit[2], olddigit[3], olddigit[4], olddigit[5], olddigit[6]};
			swap(newdigit[zero], newdigit[j]);
			newpoint[k] = newdigit[0]*1000000+newdigit[1]*100000+newdigit[2]*10000+newdigit[3]*1000+newdigit[4]*100+newdigit[5]*10+newdigit[6];
			k++;
		}
	}
}

int main()
{
	int i, j;
	for (i = 0; i < 6543211; i++)
	{
		result[i] = -1;
	}
	result[123456] = 0;
	vector<int> v1, v2;
	v1.push_back(123456);
	int count = 0;
	while (true)
	{
		bool newway = false;
		v2.clear();
		count++;
		for (i = 0; i < v1.size(); i++)
		{
			int newpoint[3] = {0};
			trans(v1[i], newpoint);
			for (j = 0; j < 3; j++)
			{
				if (newpoint[j] != 0 && result[newpoint[j]] == -1)
				{
					v2.push_back(newpoint[j]);
					result[newpoint[j]] = count;
					newway = true;
				}
			}
		}
		v1 = v2;
		if (!newway) break;
	}
	cin >> j;
	for (i = 0; i < j; i++)
	{
		int p;
		cin >> p;
		cout << result[p] << endl;
	}
}