#include<iostream>
#define PI 3.1415926535
using namespace std;
int main()
{
	int testsum,i,a;
	double x,y,s;
	cin>>testsum;
	for(i=1;i<=testsum;i++)
	{
		cin>>x>>y;
		s=(x*x+y*y)*PI/2;
		a=int(s/50)+1;
		cout<<"Property "<<i<<": This property will begin eroding in year "<<a<<".\n";
	}
	cout<<"END OF OUTPUT.";
	return 0;
}