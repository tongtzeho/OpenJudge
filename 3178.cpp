#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,i,j,a[1001];
	cin>>n;
	for(i=1;i<=n;i++)
		a[i]=1;
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j+=i)
			a[j]=-a[j];
	j=0;
	for(i=1;i<=n;i++)
		if (a[i]==1) j++;
	for(i=1;i<=n;i++)
		if (a[i]==1)
		{
			j--;
			if (j==0) cout<<i;
			else cout<<i<<' ';
		}
	return 0;
}