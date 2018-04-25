/*
  我真诚地保证：
    
      我自己独立地完成了整个程序从分析、设计到编码的所有工作。

      如果在上述过程中，我遇到了什么困难而求教于人，那么，我将在程序实习报
   告中详细地列举我所遇到的问题，以及别人给我的提示。

      我的程序里中凡是引用到其他程序或文档之处，例如教材、课堂笔记、网上的
   源代码以及其他参考书上的代码段,我都已经在程序的注释里很清楚地注明了引用
   的出处。

      我从未没抄袭过别人的程序，也没有盗用别人的程序，不管是修改式的抄袭还
   是原封不动的抄袭。

      我编写这个程序，从来没有想过要去破坏或妨碍其他计算机系统的正常运转。

      唐子豪
*/

// POJ 1375
// Intervals

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

class INTERVAL
{
public:
	double x1,x2;
	INTERVAL(double a,double b)
	{
		if(a<b)
		{
			x1=a;
			x2=b;
		}
		else
		{
			x1=b;
			x2=a;
		}
	} //令x1<x2
};

bool cmp(const INTERVAL &itv1,const INTERVAL &itv2)
{
	return (itv1.x1<itv2.x1)||(itv1.x1==itv2.x1&&itv1.x2<itv2.x2); //排序依据：x1
}

double max(const double x,const double y)
{
	if(x>y)return x;
	return y;
}

int main()
{
	int i,j,n,x,y,r,x0,y0;
	double k1,k2,x1,x2;
	vector<INTERVAL> v;
	while(cin>>n)
	{
		if(n==0)return 0;
		v.clear();
		scanf("%d%d",&x0,&y0);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&x,&y,&r);
			double a=(y0-y)*(y0-y)-r*r; //关于切线斜率的一元二次方程的二次项
			double b=2*(y0-y)*(x-x0); //关于切线斜率的一元二次方程的一次项
			double c=(x0-x)*(x0-x)-r*r; //关于切线斜率的一元二次方程的常数项
			k1=(-b+sqrt(b*b-4*a*c))/(2*a);
			k2=(-b-sqrt(b*b-4*a*c))/(2*a); //两条切线的斜率k1和k2
			x1=-y0*k1+x0;
			x2=-y0*k2+x0; //切线与x轴的两个交点的横坐标x1和x2
			v.push_back(INTERVAL(x1,x2));
		}
		sort(v.begin(),v.end(),cmp); //将各区间按x1大小排序
		j=0;
		for(i=1;i<v.size();i++)
		{
			if(v[j].x2>=v[i].x1)v[j].x2=max(v[j].x2,v[i].x2); //若后一个区间的x1比前一个区间的x2小，则两个区间有交集，将其合并
			else //两个区间没有交集，输出前一个区间的x1和x2
			{
				printf("%.2f %.2f\n",v[j].x1,v[j].x2);
				j=i;
			}
		}
		printf("%.2f %.2f\n\n",v[j].x1,v[j].x2); //输出最后一个区间的x1和x2
	}
}