#include<stdio.h>
#include<set>
#define LARGE_NUM 900000000
using namespace std;

class DEVICE
{
public:
	int b,p;
	DEVICE(){};
	DEVICE(const int b_,const int p_)
	{
		b=b_;
		p=p_;
	}
};

class cmp
{
public:
	bool operator()(const DEVICE &d1,const DEVICE &d2)const
	{
		return d1.p<d2.p;
	}
};

class COMMUNICATIONSYSTEM
{
	int n,*maxb,*minp,*minmaxb,minpsum;
	multiset<DEVICE,cmp> *s;
public:
	COMMUNICATIONSYSTEM(const int n_)
	{
		n=n_;
		int i,j,m,b,p;
		minpsum=0;
		s=new multiset<DEVICE,cmp> [n];
		multiset<int> stemp;
		multiset<int>::iterator iter;
		maxb=new int[n];
		minp=new int[n];
		minmaxb=new int[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d%d",&b,&p);
				if(!j)
				{
					maxb[i]=b;
					minp[i]=p;
				}
				else
				{
					if(b>maxb[i])maxb[i]=b;
					if(p<minp[i])minp[i]=p;
				}
				s[i].insert(DEVICE(b,p));
			}
			minpsum+=minp[i];
			stemp.insert(maxb[i]);
		}
		if(n==1)minmaxb[0]=LARGE_NUM;
		else
		{
		    for(i=0;i<n;i++)
			{
			    iter=stemp.find(maxb[i]);
			    stemp.erase(iter);
			    minmaxb[i]=*stemp.begin();
			    stemp.insert(maxb[i]);
			}
		}
	}
	double maximum()
	{
		int i,j,b,p;
		double r;
		bool t,first=0;
		multiset<DEVICE,cmp>::iterator iter1,iter2;
		for(i=0;i<n;i++)
			for(iter1=s[i].begin();iter1!=s[i].end();iter1++)
			{
				if(iter1->b<=minmaxb[i])
				{
					b=iter1->b;
					p=minpsum-minp[i]+iter1->p;
					t=double(b)/double(p)>r||!first;
					if(t)
					{
					    for(j=0;j<n;j++)
						    if(i!=j)
							{
							    for(iter2=s[j].begin();iter2!=s[j].end();iter2++)
								    if(iter2->b>=b)break;
							    p+=(iter2->p-minp[j]);
							    if(first&&double(b)/double(p)<=r)
								{
								    t=0;
								    break;
								}
							}
					}
					if(!first)
					{
						first=1;
						r=double(b)/double(p);
					}
					else if(t&&double(b)/double(p)>r)r=double(b)/double(p);
				}
			}
		return r;
	}
};

int main()
{
	int t,i,n;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n);
		COMMUNICATIONSYSTEM communicationsystem(n);
		printf("%.3lf\n",communicationsystem.maximum());
	}
	return 0;
}