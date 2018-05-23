#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a[6][6],i,j,b[6],c[6];
	for(i=1;i<=5;i++)
		for(j=1;j<=5;j++)
			cin>>a[i][j];
	for(i=1;i<=5;i++)
	{
		b[i]=1;
		for(j=1;j<=5;j++)
			if (a[i][j]>a[i][b[i]]) b[i]=j;
	}
	for(j=1;j<=5;j++)
	{
		c[j]=1;
		for(i=1;i<=5;i++)
			if (a[i][j]<a[c[j]][j]) c[j]=i;
	}
	j=0;
	for(i=1;i<=5;i++)
		if (i==c[b[i]]) 
		{
			j=1;
			cout<<i<<' '<<b[i]<<' '<<a[i][b[i]]<<endl;
		}
	if(j==0) cout<<"not found";
	return 0;
}