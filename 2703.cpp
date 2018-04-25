#include<iostream>
using namespace std;
int main()
{
	int n;
	double a;
	cin>>n;
	while(cin>>a)
		if ((50+a/3)>a/1.2) cout<<"Walk\n";
		else if ((50+a/3)==a/1.2) cout<<"All\n";
		else cout<<"Bike\n";
	return 0;
}