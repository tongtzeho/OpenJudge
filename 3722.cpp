#include<iostream>
using namespace std;
int main()
{
	int k,n,m,i,j,t;
	cin>>k;
	for(i=1;i<=k;i++)
	{
		cin>>n>>m;
		t=0;
		for(j=1;j<=m/2;j++)
			if(n%j==0&&n%(m-j)==0)
			{
				t=1;
				cout<<j<<endl;
				break;
			}
		if(t==0)cout<<-1<<endl;
	}
	return 0;
}