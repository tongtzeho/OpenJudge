#include<stdio.h>
#include<set>
#define MAX_ATK 1000000000
using namespace std;
class MAN
{
public:
	int id,atk;
	MAN(const int id_,const int atk_)
	{
		id=id_;
		atk=atk_;
	}
};
class cmp
{
public:
	bool operator()(const MAN M1,const MAN M2) const
	{
		return M1.atk<M2.atk;
	}
};
int dis(const int x,const int y)
{
	return x>y?x-y:y-x;
}
int main()
{
	set<MAN,cmp> s;
	set<MAN,cmp>::iterator iter,iterprev,iternext;
	int n,i,id,atk;
	scanf("%d",&n);
	s.insert(MAN(1,MAX_ATK));
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&id,&atk);
		s.insert(MAN(id,atk));
		iter=s.find(MAN(id,atk));
		printf("%d ",iter->id);
		iterprev=iternext=iter;
		iterprev--;
		iternext++;
		if(iter==s.end())printf("%d\n",iterprev->id);
		else if(iter==s.begin())printf("%d\n",iternext->id);
		else if(dis(atk,iternext->atk)<dis(atk,iterprev->atk))printf("%d\n",iternext->id);
		else printf("%d\n",iterprev->id);
	}
	return 0;
}