#include<iostream>
#include<cmath>
using namespace std;
int a[9]={0,1,5,8,6,3,4,7,2},b[100][9],sum=1;
bool differ(int arr[ ])
{
	int i,j;
	for(i=1;i<=8;i++)
		for(j=i+1;j<=8;j++)
			if(arr[i]==arr[j]) return false;
	return true;
}
void next(int z)
{
	int i=8,j,k,t,s,c[9],d[9];
	while(a[i-1]>a[i])
	{
		i--;
	}
	t=i;
	for(j=i;j<=8;j++)
		if(a[j]<a[t]&&a[j]>a[i-1])t=j;
	s=a[i-1];
	a[i-1]=a[t];
	a[t]=s;
	for(j=i;j<=8;j++)
		for(k=j+1;k<=8;k++)
			if(a[j]>a[k])
			{
				s=a[j];
				a[j]=a[k];
				a[k]=s;
			}
	for(i=1;i<=8;i++)
	{
		c[i]=a[i]-i;
		d[i]=a[i]+i;
	}
	if (differ(c)&&differ(d))
	{
		for(i=1;i<=8;i++)
		{
			b[sum][i]=a[i];
			//cout<<a[i];
		}
		sum++;
		//cout<<endl;
	}
	return;
}
int main()
{
	int i,n,j,k;
	for(i=1;i<=35000;i++)
	{
		next(1);
		if(sum==93)break;
	}
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>k;
		for(j=1;j<=8;j++)
			cout<<b[k][j];
		cout<<endl;
	}
	return 0;
}
