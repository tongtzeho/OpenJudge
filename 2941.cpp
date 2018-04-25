#include<iostream>
#include<cmath>
using namespace std;
void f(int a,int b)
{
	if(int(sqrt(a*a+b*b))*int(sqrt(a*a+b*b))==a*a+b*b&&a*a+b*b<=10000)cout<<a<<"*"<<a<<" + "<<b<<"*"<<b<<" = "<<int(sqrt(a*a+b*b))<<"*"<<int(sqrt(a*a+b*b))<<endl;
	if(a==98)return;
	if(b==99)f(a+1,a+2);
	else f(a,b+1);
}
int main()
{
	f(1,2);
	return 0;
}