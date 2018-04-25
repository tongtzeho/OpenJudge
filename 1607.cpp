#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double a[100000]={0};
	int i;
	for(i=1;i<=99999;i++)
		a[i]=a[i-1]+1.0/(2*i);
	cout<<"Cards  Overhang \n";
	while(cin>>i)
		cout<<setw(5)<<i<<setw(10)<<setiosflags(ios::fixed)<<setprecision(3)<<a[i]<<" \n";
	return 0;
}