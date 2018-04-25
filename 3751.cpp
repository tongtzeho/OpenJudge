#include<iostream>
using namespace std;
int main()
{
	int a,max=-999999,min=999999;
	cin>>a>>a;
	while(cin>>a)
	{
		if(a>max)max=a;
		if(a<min)min=a;
	}
	cout<<max<<' '<<min;
	return 0;
}