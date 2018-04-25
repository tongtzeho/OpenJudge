#include<iostream>
using namespace std;
int main()
{
	int n,s,a1,a[11000],b1,b[11000],i,j,k,total;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s;
		total=0;
		for(j=1;j<s;j++)
			a[j]=b[j]=0;
		cin>>a1;
		for(j=1;j<=a1;j++)
		{
			cin>>k;
			a[k]++;
		}
		cin>>b1;
		for(j=1;j<=b1;j++)
		{
			cin>>k;
			b[k]++;
		}
		for(j=1;j<s;j++)
			total+=a[j]*b[s-j];
		cout<<total<<endl;
	}
	return 0;
}