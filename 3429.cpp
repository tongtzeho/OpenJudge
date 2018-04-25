#include<stdio.h>
#include<set>
using namespace std;
class DATA
{
public:
	int n,total;
	DATA(){};
	DATA(const int n_,const int total_)
	{
		n=n_;
		total=total_;
	}
};
class cmp
{
public:
	bool operator () (const DATA &d1,const DATA &d2)const
	{
		return d1.n<d2.n;
	}
};
int main()
{
	set<DATA,cmp> s;
	set<DATA,cmp>::iterator iter;
	DATA temp;
	int n,i,m;
	char msg[4];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s%d",msg,&m);
		iter=s.find(DATA(m,1));
		if(msg[1]=='d')
		{
			if(iter!=s.end())
			{
				temp=*iter;
				temp.total++;
				printf("%d\n",temp.total);
				s.erase(iter);
				s.insert(temp);
			}
			else 
			{
				s.insert(DATA(m,1));
				printf("1\n");
			}
		}
		else if(msg[1]=='e')
		{
			if(iter!=s.end())
			{
				printf("%d\n",iter->total);
			    temp=*iter;
				temp.total=0;
				s.erase(iter);
				s.insert(temp);
			}
			else printf("0\n");
		}
		else if(msg[1]=='s')
		{
			if(iter!=s.end())printf("1 %d\n",iter->total);
			else printf("0 0\n");
		}
	}
	return 0;
}