#include<iostream>
using namespace std;
int main()
{
	int n,i,a;
	while(cin>>n)
	{
		a=i=1;
		while(a%n!=0)
		{
			a=(a*10+1)%n;
			i++;
		}
		cout<<i<<endl;
	}
	return 0;
}