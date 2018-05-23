#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	cout<<setiosflags(ios::fixed)<<setprecision(2);
	int n,x[11],y[11],z[11],i,j,a,b,cn2left[100],cn2right[100],t=1;
	double d[11][11],e[11][11],k,cn2[100];
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>x[i]>>y[i]>>z[i];
	for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
		{
			e[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]));
			cn2[t]=e[i][j];
			cn2left[t]=i;
			cn2right[t]=j;
			t++;
		}
	for(i=n*(n-1)/2;i>=2;i--)
		for(j=1;j<i;j++)
		{
			if (cn2[j]<cn2[j+1])
			{
				k=cn2[j];
				cn2[j]=cn2[j+1];
				cn2[j+1]=k;
				t=cn2left[j];
				cn2left[j]=cn2left[j+1];
				cn2left[j+1]=t;
				t=cn2right[j];
				cn2right[j]=cn2right[j+1];
				cn2right[j+1]=t;
			}
		}
	t=0;
	for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
		{	
			t++;
			cout<<'('<<x[cn2left[t]]<<','<<y[cn2left[t]]<<','<<z[cn2left[t]]
				<<")-("<<x[cn2right[t]]<<','<<y[cn2right[t]]<<','<<z[cn2right[t]]<<")="<<cn2[t]<<endl;
		}
	return 0;
}