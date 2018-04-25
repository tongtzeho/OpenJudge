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

// POJ 2431
// Expedition

#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAX_NUM 10001
using namespace std;

class FUELSTOP
{
public:
	int dis,f; //每个加油站的到目的地的距离和加油量
	FUELSTOP(){};
	FUELSTOP(int n1,int n2)
	{
		dis=n1;
		f=n2;
	}
}fuelstop[MAX_NUM];

bool cmp(const FUELSTOP &fs1,const FUELSTOP &fs2)
{
	return fs1.dis<fs2.dis; //排序依据：加油站与目的地的距离
}

int max(int x,int y)
{
	if(x>y)return x;
	return y;
}

int main()
{
	int n,l,p,i,j,sum=0;
	bool b[MAX_NUM]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d",&fuelstop[i].dis,&fuelstop[i].f);
	sort(fuelstop,fuelstop+n,cmp); //将每个加油站按到目的地的距离长短排序
	scanf("%d%d",&l,&p);
	n--;
	while(fuelstop[n].dis>l&&n>=0)
		n--; //排除在出发点之外的加油站
	while(1)
	{
		int tl=l-p,maxf=0; //tl表示耗光当前油量能到达的最远距离
		if(tl<=0) //当前油量已经足够能抵达目的地
		{
			cout<<sum;
			return 0;
		}
		j=-1;
		for(i=n;i>=0;i--)
		{
			if(fuelstop[i].dis<tl)break; //耗光当前油量也无法抵达的加油站
			if(fuelstop[i].f>maxf&&!b[i]) //油量耗光前且未加过油的加油站，选择加油量最大的，油量用maxf表示，用j记录该加油站的编号
			{
				j=i;
				maxf=fuelstop[i].f;
			}
		}
		if(j==-1) //耗光油量也无法抵达任何一个未加过油的加油站，输出-1
		{
			cout<<-1;
			return 0;
		}
		else
		{
			b[j]=1;
			p+=maxf;
			sum++;
		}
	}
}
