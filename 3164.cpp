#include<iostream>
using namespace std;
int main()
{
	int a[20]={0},b[20]={0},i,j,n,a1=0,b1=0;
	for(i=1;i<=10;i++)
	{
		cin>>n;
		if(n%2==1)
		{
			a1++;
			a[a1]=n;
		}
		else
		{
			b1++;
			b[b1]=n;
		}
	}
	for(i=1;i<=a1;i++)
		for(j=i+1;j<=a1;j++)
			if(a[i]>a[j])
			{
				n=a[i];
				a[i]=a[j];
				a[j]=n;
			}
	for(i=1;i<=b1;i++)
		for(j=i+1;j<=b1;j++)
			if(b[i]>b[j])
			{
				n=b[i];
				b[i]=b[j];
				b[j]=n;
			}
	for(i=1;i<=10;i++)
	{
		if(i<=a1)cout<<a[i];
		else cout<<b[i-a1];
		if(i<10)cout<<' ';
	}
	return 0;
}