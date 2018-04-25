#include<iostream>
using namespace std;
int main()
{
	int n,a[11000],i,j,k;
	while(1==1)
	{
		cin>>n;
		if(n==0)return 0;
		a[0]=0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			j=i;
			while(a[j]<a[j-1])
			{
				k=a[j];
				a[j]=a[j-1];
				a[j-1]=k;
				j--;
			}
		}
		if(n%2==0)cout<<(a[n/2]+a[n/2+1])/2<<endl;
		else cout<<a[n/2+1]<<endl;
	}
}