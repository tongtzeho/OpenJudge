#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a[9],b[9],i;
	for(i=0;i<9;i++)
		cin>>a[i];
	for(i=0;i<9;i++)
	{
		cin>>b[i];
		cout<<setw(4)<<a[i]+b[i];
		if(i%3==2)cout<<endl;
	}
	return 0;
}