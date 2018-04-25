#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int *a,n,mem[1001][2];
int f(int x,int y)
{
	if(x==2&&y==1)return a[2];
	if(x==2&&y==0)return a[n];
	if(mem[x][y]!=0)return mem[x][y];
	if(y==1)
	{
		mem[x][y]=a[1]+a[2]+f(x-1,0);
		return mem[x][y];
	}
	int d1,d2;
	d1=a[1]+a[n-x+2]+f(x-1,0);
	d2=a[2]+a[n-x+3]+f(x-1,1);
	mem[x][y]=d1<d2?d1:d2;
	return mem[x][y];
}
int cmp ( const void *a , const void *b )
{
    return *(int *)a - *(int *)b;
}
int main()
{
	int t,i,j;
	scanf("%d",&t);
	for(j=1;j<=t;j++)
	{
		scanf("%d",&n);
		a=new int[n+1];
		a[0]=0;
		for(i=1;i<=n;i++)
		{
			mem[i][0]=mem[i][1]=0;
			scanf("%d",&a[i]);
		}
		if(n==1)
		{
			printf("%d\n",a[1]);
			continue;
		}
		qsort(a,n+1,sizeof(int),cmp);
		printf("%d\n",f(n,1));
		delete a;
	}
	return 0;
}