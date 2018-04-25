#include <iostream>
#include <string>
#include <cstdlib>
#define inf 99999999
using namespace std;
int dis[102][102];
int main()
{
	int n,i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(i==j)dis[i][j]=0;
			else dis[i][j]=inf;
		}
	string str;
	for(i=2;i<=n;i++)
		for(j=1;j<i;j++)
		{
			cin>>str;
			if(str[0]!='x')
			{
				dis[i][j]=dis[j][i]=atoi(str.c_str());
			}
		}
	i=1;
	for(j=2;j<=n;j++)
		for(k=2;k<=n;k++)
		{
			if(dis[i][k]+dis[k][j]<dis[i][j])
			{
				dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
			}
		}
	for(j=2;j<=n;j++)
		for(k=2;k<=n;k++)
		{
			if(dis[i][k]+dis[k][j]<dis[i][j])
			{
				dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
			}
		}
	for(j=2;j<=n;j++)
		for(k=2;k<=n;k++)
		{
			if(dis[i][k]+dis[k][j]<dis[i][j])
			{
				dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
			}
		}
	for(j=2;j<=n;j++)
		for(k=2;k<=n;k++)
		{
			if(dis[i][k]+dis[k][j]<dis[i][j])
			{
				dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
			}
		}
	int maxdis=0;
	for(i=2;i<=n;i++)
		if(dis[1][i]>maxdis)maxdis=dis[1][i];
	cout<<maxdis<<endl;
	return 0;
}