#include<iostream>
using namespace std;
int main()
{
	int a[17][17]={1},i,j,n;
	for(i=1;i<=15;i++)
	{
		n=0;
		for(j=1;j<=i;j++)
		{
			a[i][j]=j*a[i-1][j]+a[i-1][j-1];
			n+=a[i][j];
		}
		a[i][16]=n;
	}
	a[0][16]=1;
	while(cin>>n)
		cout<<a[n][16]<<endl;
	return 0;
}
