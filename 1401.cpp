#include<iostream>
using namespace std;
int main()
{
	int i,j,k,n,m,s=0;
	cin>>m;
	for(i=1;i<=m;i++)
	{
		cin>>n;
		k=1;
		s=0;
		for(j=1;j<=13;j++)
		{
			k*=5;
			s+=n/k;
			if(k>=n)break;
		}
		cout<<s<<endl;
	}
	return 0;
}