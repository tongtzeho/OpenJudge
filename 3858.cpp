#include<iostream>
using namespace std;
int main()
{
	int t,n,i,j,k,l,f,sum,*a;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n;
		sum=0;
		a=new int[n+1];
		for(j=1;j<=n;j++)
			cin>>a[j];
		for(j=1;j<=n;j++)
		{
			f=0;
			for(k=1;k<=n;k++)
			{
				if(f==1)break;
				for(l=k+1;l<=n;l++)
					if(a[k]+a[l]==a[j]&&k!=j&&l!=j) 
					{
						sum++;
						f=1;
						break;
					}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}