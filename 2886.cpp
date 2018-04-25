#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
		cout<<(n-n%3+3)*((n-n%3)/3)/2<<endl;
	return 0;
}