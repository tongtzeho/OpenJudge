#include<stdio.h>
#include<iostream>
using namespace std;
int year[30000]={1970},month[30000]={1},day[30000]={1};
bool isleepyear(int y,int m)
{
	return(m==2&&(y%400==0||(y%4==0&&y%100!=0)));
}
int main()
{
	const int md[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int yy=1970,mm=1,dd=1,i,n;
	for(i=1;i<30000;i++)
	{
		dd++;
		if(dd>md[mm]+isleepyear(yy,mm))
		{
			mm++;
			dd=1;
		}
		if(mm>12)
		{
			yy++;
			mm=dd=1;
		}
		year[i]=yy;
		month[i]=mm;
		day[i]=dd;
	}
	while(cin>>n)
	{
		int date,t;
		date=n/86400;
		t=n%86400;
		yy=year[date];
		mm=month[date];
		dd=day[date];
		int h,m,s;
		h=t/3600;
		t%=3600;
		m=t/60;
		s=t%60;
		printf("%d-%02d-%02d %02d:%02d:%02d\n",yy,mm,dd,h,m,s);
	}
	return 0;
}
