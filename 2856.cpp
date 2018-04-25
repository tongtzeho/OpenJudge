#include<iostream>
#include<cmath>
using namespace std;
int main( )
{
	double weight,cost;
	char exp;
	while(cin>>weight>>exp)
	{
	    if (weight<=1) cost=0.8;
	    if (weight>1) cost=0.8+0.5*(weight-1);
	    if (exp=='y') cost=cost+2;
	    cout<<cost<<endl;
	}
	return 0;
}