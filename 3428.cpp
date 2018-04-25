#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<list>
#include<set>
using namespace std;

class MEMORY
{
	multiset<double> mts;
public:
	void write(const double n)
	{
		mts.erase(mts.begin());
		mts.insert(n);
	}
	void insert(const double n)
	{
		mts.insert(n);
	}
	void output()
	{
		int numsum=0;
		multiset<double>::iterator iter;
		for(iter=mts.begin();iter!=mts.end();numsum++,iter++)
		{
			if(numsum%10==0)printf("\n%e",*iter);
			else printf(" %e",*iter);
		}
	}
};

class RPNCALCULATOR
{
	list<double> lst;
	double count(const double x,const double y,const char ope)
	{
		if(ope=='+')return x+y;
		else if(ope=='-')return x-y;
		else if(ope=='*')return x*y;
		else if(ope=='/')return x/y;
		else return pow(x,y);
	}
public:
	bool calculate(double &result)
	{
		double x,y;
		char ch[25];
		lst.clear();
		while(scanf("%s",ch)!=EOF)
		{
			if(strlen(ch)==1&&ch[0]=='=')
			{
				result=lst.back();
				return true;
			}
			else if(strlen(ch)==1&&(ch[0]=='+'||ch[0]=='-'||ch[0]=='*'||ch[0]=='/'||ch[0]=='^'))
			{
				y=lst.back();
				lst.pop_back();
				x=lst.back();
				lst.pop_back();
				lst.push_back(count(x,y,ch[0]));
			}
			else lst.push_back(atof(ch));
		}
		return false;
	}
};

int main()
{
	MEMORY memory;
	RPNCALCULATOR calculator;
	int size,i;
	scanf("%d",&size);
	double temp;
	for(i=0;i<size;i++)
	{
		scanf("%lf",&temp);
		memory.insert(temp);
	}
	while(calculator.calculate(temp))
	{
		printf("%e\n",temp);
		memory.write(temp);
	}
	memory.output();
	return 0;
}