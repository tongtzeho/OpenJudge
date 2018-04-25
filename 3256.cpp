#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int a[101][101],b[101][101],c[101][101],x1,x2,y1,y2,i,j,k;
	cin>>x1>>y1;
	for(i=1;i<=x1;i++)
		for(j=1;j<=y1;j++)
			cin>>a[i][j];
	cin>>x2>>y2;
	for(i=1;i<=x2;i++)
		for(j=1;j<=y2;j++)
			cin>>b[i][j];
    for(i=1;i<=x1;i++)
		for(j=1;j<=y2;j++)
		{
			c[i][j]=0;
			for(k=1;k<=x2;k++)
				c[i][j]+=a[i][k]*b[k][j];
			cout<<setw(5)<<c[i][j];
			if (j==y2) cout<<endl;
		}
	return 0;
}