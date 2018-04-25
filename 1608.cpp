#include <iostream>
#include <cstdio>
#include <string>
#define max(x,y) x>y?x:y
using namespace std;

long long count[56][38][20][20][19]={0};
long long zerocount[18]={0,1};
long long allcount[18]={0,10};

int main()
{
	count[0][0][0][0][1]=1;
	count[1][0][0][0][1]=1;
	count[0][1][0][0][1]=1;
	count[2][0][0][0][1]=1;
	count[0][0][1][0][1]=1;
	count[1][1][0][0][1]=1;
	count[0][0][0][1][1]=1;
	count[3][0][0][0][1]=1;
	count[0][2][0][0][1]=1;
	int i,j,k,l,m;
	long long max=0;
	for(m=2;m<=18;m++)
	{
		for(i=0;i<=3*m;i++)
		{
			for(j=0;j<=2*m;j++)
			{
				for(k=0;k<=m;k++)
				{
					for(l=0;l<=m;l++)
					{
						count[i][j][k][l][m]=count[i][j][k][l][m-1];
						if(i>=1)count[i][j][k][l][m]+=count[i-1][j][k][l][m-1];
						if(j>=1)count[i][j][k][l][m]+=count[i][j-1][k][l][m-1];
						if(i>=2)count[i][j][k][l][m]+=count[i-2][j][k][l][m-1];
						if(k>=1)count[i][j][k][l][m]+=count[i][j][k-1][l][m-1];
						if(i>=1&&j>=1)count[i][j][k][l][m]+=count[i-1][j-1][k][l][m-1];
						if(l>=1)count[i][j][k][l][m]+=count[i][j][k][l-1][m-1];
						if(i>=3)count[i][j][k][l][m]+=count[i-3][j][k][l][m-1];
						if(j>=2)count[i][j][k][l][m]+=count[i][j-2][k][l][m-1];
						if(count[i][j][k][l][m]>max)max=count[i][j][k][l][m];
					}
				}
			}
		}
	}
	for(m=2;m<=18;m++)
	{
		allcount[m]=allcount[m-1]*10;
		zerocount[m]=9*zerocount[m-1]+allcount[m-1];
	}
	int n;
	cin>>n;
	string str;
	cin>>str;
	bool lzero=false,rzero=false;
	int l2=0,l3=0,l5=0,l7=0,r2=0,r3=0,r5=0,r7=0,lx=0,rx=0;
	for(i=0;i<n;i++)
	{
		if(str[i]=='0')lzero=true;
		else if(str[i]=='2')l2++;
		else if(str[i]=='3')l3++;
		else if(str[i]=='4')l2+=2;
		else if(str[i]=='5')l5++;
		else if(str[i]=='6')
		{
			l2++;
			l3++;
		}
		else if(str[i]=='7')l7++;
		else if(str[i]=='8')l2+=3;
		else if(str[i]=='9')l3+=2;
		else if(str[i]=='?')lx++;
	}
	for(i=n;i<2*n;i++)
	{
		if(str[i]=='0')rzero=true;
		else if(str[i]=='2')r2++;
		else if(str[i]=='3')r3++;
		else if(str[i]=='4')r2+=2;
		else if(str[i]=='5')r5++;
		else if(str[i]=='6')
		{
			r2++;
			r3++;
		}
		else if(str[i]=='7')r7++;
		else if(str[i]=='8')r2+=3;
		else if(str[i]=='9')r3+=2;
		else if(str[i]=='?')rx++;
	}
	long long answer=0;
	if(!lzero&&!rzero)
	{
		for(i=max(l2,r2);i<=3*n;i++)
			for(j=max(l3,r3);j<=2*n;j++)
				for(k=max(l5,r5);k<=n;k++)
					for(l=max(l7,r7);l<=n;l++)
						answer+=count[i-l2][j-l3][k-l5][l-l7][lx]*count[i-r2][j-r3][k-r5][l-r7][rx];
		answer+=zerocount[lx]*zerocount[rx];
	}
	else if(lzero&&rzero)
	{
		answer=allcount[lx]*allcount[rx];
	}
	else if(lzero)
	{
		answer=allcount[lx]*zerocount[rx];
	}
	else
	{
		answer=zerocount[lx]*allcount[rx];
	}
	//printf("%I64d\n%I64d",answer,allcount[lx+rx]-answer);
	cout<<answer<<endl<<allcount[lx+rx]-answer<<endl;
	return 0;
}