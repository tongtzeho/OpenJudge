#include <cstdio>

class MY_HEAP
{
	int size;
public:
	int n[100005];
	MY_HEAP()
	{
		size = 0;
	}
	int top()
	{
		return n[0];
	}
	void push(int x)
	{
		n[size] = x;
		size++;
		int upshiftpos = size-1;
		while (upshiftpos > 0 && n[upshiftpos] < n[(upshiftpos-1)/2])
		{
			n[upshiftpos] ^= n[(upshiftpos-1)/2];
			n[(upshiftpos-1)/2] ^= n[upshiftpos];
			n[upshiftpos] ^= n[(upshiftpos-1)/2];
			upshiftpos = (upshiftpos-1)/2;
		}
	}
	void pop()
	{
		size--;
		n[0] = n[size];
		int dnshiftpos = 0;
		while (2*dnshiftpos+1 < size && (n[dnshiftpos] >= n[2*dnshiftpos+1] || (2*dnshiftpos+2 < size && n[dnshiftpos] >= n[2*dnshiftpos+2])))
		{
			if (n[dnshiftpos] >= n[2*dnshiftpos+1] && (2*dnshiftpos+2 == size || n[2*dnshiftpos+1] <= n[2*dnshiftpos+2]))
			{
				n[dnshiftpos] ^= n[2*dnshiftpos+1];
				n[2*dnshiftpos+1] ^= n[dnshiftpos];
				n[dnshiftpos] ^= n[2*dnshiftpos+1];
				dnshiftpos = 2*dnshiftpos+1;
			}
			else if (2*dnshiftpos+2 < size && n[2*dnshiftpos+2] <= n[dnshiftpos] && n[2*dnshiftpos+2] <= n[2*dnshiftpos+1])
			{
				n[dnshiftpos] ^= n[2*dnshiftpos+2];
				n[2*dnshiftpos+2] ^= n[dnshiftpos];
				n[dnshiftpos] ^= n[2*dnshiftpos+2];
				dnshiftpos = 2*dnshiftpos+2;				
			}
		}
	}
	void clear()
	{
		size = 0;
	}
}q;

int main()
{
	int i, n, t, k;
	scanf("%d", &t);
	for (k = 0; k < t; k++)
	{
		q.clear();
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			int a, b;
			scanf("%d", &a);
			if (a == 1)
			{
				scanf("%d", &b);
				q.push(b);
			}
			else
			{
				printf("%d\n", q.top());
				q.pop();
			}
		}
	}
	return 0;
}
