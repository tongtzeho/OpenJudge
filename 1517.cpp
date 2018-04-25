#include<iostream>
#include<iomanip>
using namespace std;

int fact(const int n)
{
	int i,j=1;
	for(i=2;i<=n;i++)
		j*=i;
	return j;
}

int main()
{
	cout<<"n e\n- -----------\n";
	int i,j;
	double a;
	for(i=0;i<=9;i++)
	{
		a=0;
		for(j=0;j<=i;j++)
			a+=1.0/fact(j);
		cout<<i<<" "<<setprecision(10)<<a;
		if(i==8)cout<<0;
		cout<<endl;
	}
	return 0;
}