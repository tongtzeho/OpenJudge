#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a[101][101],b[101][101],c[101][101]={0},ra,ca,rb,cb,i,j,k,rc,cc;
	cin>>ra>>ca;
	for(i=1;i<=ra;i++)
		for(j=1;j<=ca;j++)
			cin>>a[i][j];
	cin>>rb>>cb;
	for(i=1;i<=rb;i++)
		for(j=1;j<=cb;j++)
			cin>>b[i][j];
	if(ca==rb)
	{
		rc=ra;
		cc=cb;
		for(i=1;i<=rc;i++)
			for(j=1;j<=cc;j++)
				for(k=1;k<=ca;k++)
					c[i][j]+=a[i][k]*b[k][j];
		for(i=1;i<=cc;i++)
		{
		    for(j=1;j<=rc;j++)
			    cout<<setw(5)<<c[j][i];
		    cout<<endl;
		}
	}
	else
	{
		rc=ca;
		cc=ra;
		for(i=1;i<=rc;i++)
			for(j=1;j<=cc;j++)
				c[i][j]=a[j][i];
		for(i=1;i<=rc;i++)
		{
		    for(j=1;j<=cc;j++)
			    cout<<setw(5)<<c[i][j];
		    cout<<endl;
		}
	}
	return 0;
}