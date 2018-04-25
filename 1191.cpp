#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int mem[10][10][10][10][16]={0},sum[10][10][10][10]={0};
int div(const int x1,const int y1,const int x2,const int y2,const int k,const int t)//1 left 2 up 3 right 4 down
{
	if(k<=0)
	{
		return 0;
	}
	if(mem[x1][y1][x2][y2][k]!=0)
	{
		return mem[x1][y1][x2][y2][k];
	}
	int i,temp,result=0;
	//left right
	for(i=y1;i<y2;i++)
	{
		if(x2-x1+i-y1>=k-1)
		{
			temp=div(x1,y1,x2,i,k-1,1)+sum[x1][y1][x2][i]*sum[x1][i+1][x2][y2];
			if(temp>result)result=temp;
		}
		if(t!=1&&x2-x1+y2-i-1>=k-1)
		{
			temp=sum[x1][y1][x2][i]*sum[x1][i+1][x2][y2]+div(x1,i+1,x2,y2,k-1,2);
			if(temp>result)result=temp;
		}
	}
	//up down
	for(i=x1;i<x2;i++)
	{
		if(y2-y1+i-x1>=k-1)
		{
			temp=div(x1,y1,i,y2,k-1,3)+sum[x1][y1][i][y2]*sum[i+1][y1][x2][y2];
			if(temp>result)result=temp;
		}
		if(t!=3&&y2-y1+x2-i-1>=k-1)
		{
			temp=sum[x1][y1][i][y2]*sum[i+1][y1][x2][y2]+div(i+1,y1,x2,y2,k-1,4);
			if(temp>result)result=temp;
		}
	}
	mem[x1][y1][x2][y2][k]=result;
	return result;
}
int main()
{
	int n,i,j,k,l;
	double qt;
	cin>>n;
	for(i=1;i<=8;i++)
		for(j=1;j<=8;j++)
		{
			cin>>sum[i][j][i][j];
			for(l=j-1;l>=1;l--)
				sum[i][l][i][j]=sum[i][l][i][j-1]+sum[i][j][i][j];
			for(k=i-1;k>=1;k--)
				for(l=j;l>=1;l--)
					sum[k][l][i][j]=sum[k][l][i-1][j]+sum[i][l][i][j];
		}
	k=div(1,1,8,8,n-1,0);
	qt=sqrt((sum[1][1][8][8]*sum[1][1][8][8]*(n-1)/double(n)-2*k)/n);
	cout<<setiosflags(ios::fixed)<<setprecision(3)<<qt<<endl;
	return 0;
}
