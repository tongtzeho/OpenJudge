#include <cstdio>
using namespace std;

int main()
{
	int n, m, father[30005], groupid[30005];
	while (scanf("%d%d", &n, &m))
	{
		if (n==0 && m==0)
		{
			break;
		}
		int i,j,k;
		for (i = 0; i <= n; i++)
		{
			father[i] = i;
		}
		for (i = 0; i < m; i++)
		{
			int d;
			int fatherid = 9999999;
			scanf("%d", &d);
			if (d == 0)
			{
				continue;
			}
			for (j = 0; j < d; j++)
			{
				scanf("%d", groupid+j);
				int root = father[groupid[j]];
				do
				{
					root = father[root];
				}
				while (root != father[root]);
				if (root < fatherid)
				{
					fatherid = root;
				}
			}
			do
			{
				fatherid = father[fatherid];
			}
			while (father[fatherid] != fatherid);
			for (j = 0; j < d; j++)
			{
				int temp = groupid[j];
				int next = temp;
				do
				{
					temp = next;
					next = father[temp]; 
					father[temp] = fatherid;
				}
				while (temp != next);
			}
		}
		int sicknum = 0;
		for (i = 0; i <= n; i++)
		{
			int root = i;
			do
			{
				root = father[root];
			}
			while (father[root] != root);
			if (root == 0)
			{
				sicknum++;
			}
		}
		printf("%d\n", sicknum);
	}
	return 0;
}