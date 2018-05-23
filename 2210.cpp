#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n,i,j,k,secin,minin,hourin,dayin,monthin,yearin,secout,minout,hourout,dayout,monthout,yearout;
	int d1,s1,s2,e;
	int dm[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d:%d:%d %d.%d.%d",&hourin,&minin,&secin,&dayin,&monthin,&yearin);
		d1=(yearin-2000)*365+dm[monthin-1]+dayin-1;
		s1=hourin*3600+minin*60+secin;
		if(monthin>2)e=yearin;
		else e=yearin-1;
		if(e>=2000)
		{
			d1+=(e-2000)/4+1;
			d1-=(e-2000)/100;
			d1+=(e-2000)/400;
		}
		dayout=d1%100+1;
		d1/=100;
		monthout=d1%10+1;
		d1/=10;
		yearout=d1;
		s2=int(s1*double(100000)/86400);
		secout=s2%100;
		s2/=100;
		minout=s2%100;
		s2/=100;
		hourout=s2;
		printf("%d:%d:%d %d.%d.%d\n",hourout,minout,secout,dayout,monthout,yearout);
	}
	return 0;
}