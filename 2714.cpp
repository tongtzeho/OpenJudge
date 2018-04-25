#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n,i,a;
	double sum=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		sum+=a;
	}
	sum/=n;
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<sum;
	return 0;
}