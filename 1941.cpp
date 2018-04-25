#include<stdio.h>

class ROW
{
public:
	int n,*a;
	void create(int n_)
	{
		n=n_;
		a=new int[n+1];
	}
};

class TRIANGLE
{
public:
	int n;
	ROW *row;
	void create(int n_)
	{
		n=n_;
		row=new ROW[n+1];
	}
	void copy(TRIANGLE &C)
	{
		int i,j;
		n=2*C.n;
		row=new ROW[n+1];
		for(i=1;i<=C.n;i++)
		{
			row[i].create(C.row[i].n);
			for(j=1;j<=C.row[i].n;j++)
			{
				row[i].a[j]=C.row[i].a[j]+C.n;
			}
		}
		for(i=C.n+1;i<=n;i++)
		{
			row[i].create(C.row[i-C.n].n*2);
			for(j=1;j<=C.row[i-C.n].n;j++)
			{
				row[i].a[j]=C.row[i-C.n].a[j];
			}
			for(j=C.row[i-C.n].n+1;j<=row[i].n;j++)
			{
				row[i].a[j]=C.row[i-C.n].a[j-C.row[i-C.n].n]+n;
			}
		}
	}
	void output()
	{
		int i,j,k;
		for(i=1;i<=n;i++)
		{
			printf(" ");
			j=k=1;
			while(k<=row[i].n)
			{
				if(row[i].a[k]==j)
				{
					k++;
					j++;
					printf("/\\");
				}
				else
				{
					j++;
					printf("  ");
				}
			}
			printf("\n");
			j=k=1;
			while(k<=row[i].n)
			{
				if(row[i].a[k]==j)
				{
					k++;
					j+=2;
					printf("/__\\");
				}
				else
				{
					j++;
					printf("  ");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
}tri[11];

int main()
{
	int i,n;
	tri[1].create(1);
	tri[1].row[1].create(1);
	tri[1].row[1].a[1]=1;
	for(i=2;i<=10;i++)
		tri[i].copy(tri[i-1]);
	while(1)
	{
		scanf("%d",&n);
		if(n==0)return 0;
		else tri[n].output();
	}
}