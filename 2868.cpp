#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main( )
{
	double x[20],root=1,sqrtx;
	int n=1,i=0;
	for(i=0;i<=19;i++)
		x[i]=-1;
	cin>>x[1]>>x[2]>>x[3]>>x[4]>>x[5]>>x[6]>>x[7]>>x[8]>>x[9]>>x[10]>>x[11]>>x[12]>>x[13]>>x[14];
	i=1;
	while(x[i]>0)
	{
    n=1;
	sqrtx=sqrt(x[i]);
	root=1;
	do
	{
		root=(root+x[i]/root)/2;
		n++;
	} while ((root-sqrtx)>1E-6||(sqrtx-root)>1E-6);
	if (x[i]==1) n--;
	cout<<n<<' ';
    cout<<setprecision(2)<< setiosflags(ios::fixed)<<root<<endl;
	i++;
	}
	return 0;
}