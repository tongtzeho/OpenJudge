#include<iostream>
using namespace std;
int main()
{
	int n,i,a;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		if(a%2==1)cout<<"0 0"<<endl;
		else cout<<(a+2)/4<<' '<<a/2<<endl;
	}
	return 0;
}