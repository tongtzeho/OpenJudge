#include<iostream>
using namespace std;
int main()
{
	int a[102][102],i,j,s=0,c=0,n;
	cin>>n;
	for(i=1;i<=n;i++)
		a[i][0]=a[0][i]=a[i][n+1]=a[n+1][i]=255;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]<=50) s++;
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][j]<=50&&(a[i-1][j]>50||a[i+1][j]>50||a[i][j-1]>50||a[i][j+1]>50)) c++;
	cout<<s<<' '<<c;
	return 0;
}