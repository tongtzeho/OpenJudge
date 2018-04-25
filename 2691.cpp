#include<iostream>
using namespace std;
int main()
{
	int n,k,i,j,s,t,a[100]={0};
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>k;
		t=0;
		for(j=1;j<=k;j++)
		{
			cin>>a[j];
			if(j==2)
				if(a[1]!=a[2]) 
				{
					t=1;
					cout<<0;
				}
			if(j>2&&((a[j-1]>a[j])&&(a[j-1]>a[j-2])||(a[j-1]<a[j])&&(a[j-1]<a[j-2])))
			{
				if(t==1)cout<<' ';
				cout<<j-2;
				t=1;
			}
		}
		if(a[k]!=a[k-1]) cout<<' '<<k-1;
		cout<<endl;
	}
	return 0;
}