#include<stdio.h>

class POINT;
class TREE;
class FOREST;

class POINT
{
	friend class TREE;
	friend class FOREST;
	short n;
	POINT()
	{
		n=0;
	}
};

class TREE
{
	friend class FOREST;
	POINT *p;
	void init(const int h)
	{
		p=new POINT[h+1];
	}
};

class FOREST
{
	int n,h,d;
	TREE *tree;
public:
	void init(const int n_,const int h_,const int d_)
	{
		n=n_;
		h=h_;
		d=d_;
		tree=new TREE[n+1];
		int i,j,temp;
		for(i=1;i<=n;i++)
		{
			tree[i].init(h);
			scanf("%d",&j);
			for( ;j>=1;j--)
			{
				scanf("%d",&temp);
				tree[i].p[temp].n++;
			}
		}
	}
	void search()
	{
		int max,i,j;
		for(i=2;i<=h;i++)
		{
			if(i<=d)
			{
				for(j=1;j<=n;j++)
					tree[j].p[i].n+=tree[j].p[i-1].n;
			}
			else
			{
				max=0;
				for(j=1;j<=n;j++)
					if(tree[j].p[i-d].n>max)max=tree[j].p[i-d].n;
				for(j=1;j<=n;j++)
				{
					if(max>tree[j].p[i-1].n)tree[j].p[i].n+=max;
					else tree[j].p[i].n+=tree[j].p[i-1].n;
				}
			}
		}
		max=0;
		for(i=1;i<=n;i++)
			if(tree[i].p[h].n>max)max=tree[i].p[h].n;
		printf("%d",max);
	}
}forest;

int main()
{
	int n,h,d;
	scanf("%d%d%d",&n,&h,&d);
	forest.init(n,h,d);
	forest.search();
	return 0;
}