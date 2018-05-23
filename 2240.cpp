#include <iostream>
#include <string>
using namespace std;

string moneyname[35];
double dist[35][35];

int main()
{
	int t1, t2, i, j, k, casenum = 0;
	string st1, st2;
	while (true)
	{
		cin>>t1;
		if (t1 == 0) break;
		casenum++;
		for (i = 0; i < t1; i++)
		{
			cin>>moneyname[i];
		}
		for (i = 0; i < t1; i++)
			for (j = 0; j < t1; j++)
				dist[i][j] = -1;
		cin>>t2;
		for (i = 0; i < t2; i++)
		{
			double temp;
			cin>>st1>>temp>>st2;
			for (j = 0; j < t1; j++)
				if (st1 == moneyname[j]) break;
			for (k = 0; k < t1; k++)
				if (st2 == moneyname[k]) break;
			dist[j][k] = temp;
		}
		for (i = 0; i < t1; i++)
			for (j = 0; j < t1; j++)
				for (k = 0; k < t1; k++)
				{
					if (dist[i][k] > 0 && dist[k][j] > 0 && dist[i][k]*dist[k][j] > dist[i][j])
					{
						dist[i][j] = dist[i][k]*dist[k][j];
					}
				}
		int result = 0;
		for (i = 0; i < t1; i++)
			if (dist[i][i] > 1) result = 1;
		if (result == 1) cout<<"Case "<<casenum<<": Yes"<<endl;
		else cout<<"Case "<<casenum<<": No"<<endl;
	}
	return 0;
}