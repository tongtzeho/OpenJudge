#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int n,i,j;
	cin>>n;
	double x[500],y[500],dis=0;
	for(i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		for(j=1;j<i;j++)
			if (dis<sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))) dis=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
	}
	cout<<setiosflags(ios::fixed)<<setprecision(4)<<dis;
	return 0;
}
