#include<iostream>
using namespace std;
int main()
{
	int n,i,s=0,t=1,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		t=1;
		for(j=2;j<=i;j++)
			t*=j;
		s+=t;
	}
	cout<<s;
	return 0;
}