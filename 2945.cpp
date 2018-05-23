#include<iostream>
using namespace std;
int order(double a[ ],int n)
{
	int f,t=0,i,j,k;
	double b[101]={2000000};
	for(i=1;i<=n;i++)
	{
		k=0;
		for(j=i+1;j<=n;j++)
			if(a[i]>=a[j])
			{
				k++;
				b[k]=a[j];
			}
		j=order(b,k);
		if (t<j) t=j;
	}
	f=t+1;
	return f;
}
int main()
{
	int i,j,n,sum=0;
	double a[101];
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	cout<<order(a,n)-1;
	return 0;
}