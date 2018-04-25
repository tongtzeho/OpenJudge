#include<iostream>
using namespace std;
int main()
{
	int a,i,n,s=0;
	cin>>a>>n;
	for(i=1;i<=n;i++)
	{
		s+=a;
		a=a*10+a%10;
	}
	cout<<s<<endl;
	return 0;
}