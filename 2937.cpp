#include<iostream>
using namespace std;
int main()
{
	int a[102][102]={0},n,i,j,sum=0;
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(i>1)
				if(a[i-1][j]<=a[i-1][j-1]-50&&a[i-1][j]<=a[i-1][j+1]-50&&a[i-1][j]<=a[i][j]-50&&a[i-1][j]<=a[i-2][j]-50)sum++;
		}
	cout<<sum;
	return 0;
}