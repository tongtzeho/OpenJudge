#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double a,b=0;
	while(cin>>a)
		b+=a;
	cout<<'$'<<setiosflags(ios::fixed)<<setprecision(2)<<b/12;
	return 0;
}