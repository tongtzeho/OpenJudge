#include<iostream>
#include<cmath>
#include<set>
using namespace std;
int mem[10000000]={0};
int primefactor(int x)
{
	if(x<=2)return 0;
	if(mem[x]!=0)return mem[x];
	int xtemp=x,r=0;
	if(x%2==0)
	{
		r=1;
		while(x%2==0)
			x/=2;
	}
	int k=int(sqrt(x));
	for(int i=3;i<=k;i+=2)
	{
		if(x%i==0)
		{
			r++;
			while(x%i==0)
				x/=i;
		}
		if(x==1)break;
	}
	if(x!=1&&x!=xtemp)mem[xtemp]=r+1;
	else mem[xtemp]=r;
	return mem[xtemp];
}
class cmp
{
public:
	bool operator() (const int x,const int y)
	{
		int a=primefactor(x),b=primefactor(y);
		if(a!=b)return a<b;
		else return x<y;
	}
};
int main()
{
	set<int,cmp> s;
	set<int,cmp>::iterator iter;
	int num,i,j,n;
	cin>>num;
	for(i=1;i<=num;i++)
	{
		for(j=1;j<=10;j++)
		{
			cin>>n;
			s.insert(n);
		}
		iter=s.end();
		iter--;
		cout<<*iter;
		s.erase(iter);
		iter=s.begin();
		cout<<" "<<*iter<<endl;
		s.erase(iter);
	}
	return 0;
}