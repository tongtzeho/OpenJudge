#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n,m,i,j,sum,a[1001],k;
	double avg;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>m;
		sum=0;
		for(j=1;j<=m;j++)
		{
			cin>>a[j];
			sum+=a[j];
		}
		avg=sum/double(m);
		k=0;
		for(j=1;j<=m;j++)
			if(a[j]>avg)k++;
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<double(k)/m*100<<"%\n";
	}
	return 0;
}