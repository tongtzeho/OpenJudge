#include<iostream>
using namespace std;
int main()
{
	int i,s,n;
	cin>>n;
	s=2;
	for(i=1;i<=n;i++)
	{
		cout<<s+1<<endl;
		s*=s;
	}
	return 0;
}
