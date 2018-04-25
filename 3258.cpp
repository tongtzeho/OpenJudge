#include<iostream>
using namespace std;
int main()
{
	int n,m,i,j,a,b,c;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>m;
		a=b=1;
		for(j=1;j<=m;j++)
		{
			cout<<a;
			if(j<m)cout<<" ";
			else cout<<endl;
			c=a+b;
			a=b;
			b=c;
		}
	}
	return 0;
}