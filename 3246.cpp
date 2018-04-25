#include<iostream>
using namespace std;
int main()
{
	int x[1001],y[1001],total[2001]={0},n,i,j;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>x[i];
	for(i=1;i<=n;i++)
		cin>>y[i];
	for(i=1;i<=n;i++)
		for(j=x[i];j<y[i];j++)
			total[j]++;
	n=0;
	for(i=1;i<=2000;i++)
		if(total[i]>n)n=total[i];
	cout<<n;
	return 0;
}
