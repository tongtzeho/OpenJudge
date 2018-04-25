#include<iostream>
#include<ctime>
using namespace std;
int time1[120]={0},weight[120]={0},weighttotal[120]={0},timeleast[120]={0},timesum=0,weightsum=0,weightmax=0;
time_t start,end;
void change(int t,int n)
{
	timesum+=t*time1[n];
	weightsum+=t*weight[n];
	if(weightsum>weightmax)weightmax=weightsum;
}
void f(int n,int m,int timelimit)
{
	int i;
	end=clock();
	if(int(end-start)>960)return;
	change(1,n);
	for(i=n+1;i<=m;i++)
	{
		if(weightsum+weighttotal[i]<=weightmax||timesum+timeleast[i]>timelimit)break;
		if(weightsum+weighttotal[i]>weightmax&&timesum+time1[i]<=timelimit)f(i,m,timelimit);
	}
	change(-1,n);
	return;
}
int main()
{
	int m,i,j,k,p,timelimit,least=2000;
	double a[120]={0},t;
	cin>>timelimit>>m;
	for(i=1;i<=m;i++)
	{
		cin>>time1[i]>>weight[i];
		a[i]=(time1[i]>timelimit)?-1:double(weight[i])/time1[i];
	}
	start=clock();
	for(i=1;i<=m;i++)
		for(j=i+1;j<=m;j++)
			if(a[i]<a[j])
			{
				k=time1[i];
				time1[i]=time1[j];
				time1[j]=k;
				t=a[i];
				a[i]=a[j];
				a[j]=t;
				k=weight[i];
				weight[i]=weight[j];
				weight[j]=k;
			}
	k=t=0;
	p=m;
	for(i=p;i>=1;i--)
	{
		if(a[i]>0&&t==0)
		{
			t=1;
			m=i;
		}
		if(t==1)
		{
			k+=weight[i];
			weighttotal[i]=k;
			if(time1[i]<least)least=time1[i];
			timeleast[i]=least;
		}
	}
	for(i=1;i<=m;i++)
	{
		if(weightsum+weighttotal[i]<=weightmax||timesum+timeleast[i]>timelimit)break;
		if(weightsum+weighttotal[i]>weightmax&&timesum+time1[i]<=timelimit)f(i,m,timelimit);
	}
    cout<<weightmax<<endl;
	return 0;
}