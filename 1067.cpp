#include<iostream>
#include<cmath>
using namespace std;
const double goldensection=(sqrt(5.0)+1)/2;
int f(int x)
{
	if(int(x/goldensection)==int((x+1)/goldensection))return int(x/goldensection);
	if(x*goldensection==int(x*goldensection))return int(x*goldensection);
	return 1+int(x*goldensection);
}
int main()
{
	int a,b;
	while(cin>>a>>b)
		f(a)==b||f(b)==a?cout<<"0\n":cout<<"1\n";
	return 0;
}