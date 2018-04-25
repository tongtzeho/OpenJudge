#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int n,i,most=1;
	float *a;
	cin>>n;
	a=new float[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(i>=1)
			if(a[i-1]/a[i]>a[most-1]/a[most])most=i;
	}
	cout<<setiosflags(ios::fixed)<<setprecision(6)<<a[most-1]<<" / "<<a[most]<<" = "<<float(a[most-1]/a[most]);
	return 0;
}