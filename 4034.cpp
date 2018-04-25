#include<stdio.h>
#include<list>
using namespace std;

class RIVERBANK
{
	int n,k,p,*a,*b,sum;
public:
	RIVERBANK(const int n_,const int k_,const int p_)
	{
		n=n_;
		k=k_;
		p=p_;
		sum=0;
		a=new int[k];
		b=new int[k];
		for(int i=0;i<k;i++)
			a[i]=b[i]=0;
	}
	void count()
	{
		int i,j,color,price;
		list<int> lst;
		list<int>::iterator iter;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&color,&price);
			if(price<=p)
			{
				for(iter=lst.begin();iter!=lst.end();iter++)
				{
					a[*iter]+=b[*iter];
					b[*iter]=0;
				}
				lst.clear();
				sum+=a[color];
				a[color]++;
			}
			else
			{
				sum+=a[color];
				b[color]++;
				lst.push_back(color);
			}
		}
	}
	void output()
	{
		printf("%d",sum);
	}
};

int main()
{
	int n,k,p;
	scanf("%d%d%d",&n,&k,&p);
	RIVERBANK bank(n,k,p);
	bank.count();
	bank.output();
	return 0;
}