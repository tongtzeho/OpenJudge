#include<iostream>
using namespace std;
int main()
{
	int n,m,i,j,a[102]={0};
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			cin>>m;
			if(m==3)a[i]++;
		}
	m=1;
	for(i=2;i<=n;i++)
		if(a[i]>a[m])m=i;
	cout<<m;
	return 0;
}