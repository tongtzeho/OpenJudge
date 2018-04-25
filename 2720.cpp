#include<iostream>
using namespace std;
int main( )
{
	int h,r,k,v;
	double a,pai=3.14159;
	cin>>h>>r;
	v=pai*h*r*r;
	a=20000/v;
	k=(int)a+1;
	cout<<k;
	return 0;
}