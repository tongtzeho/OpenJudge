#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,i,j,a[1001],m;
	cin>>n;
while(cin>>n)
{m=0;
	for(i=1;i<=n;i++)
		a[i]=1;
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j+=i)
			a[j]=-a[j];
	for(i=1;i<=n;i++)
		if (a[i]==-1)
		{
			m++;		}cout<<m<<endl;}
	return 0;
}