#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a[6][6],i,j,b,c,d,e;
	for(i=1;i<=5;i++)
		for(j=1;j<=5;j++)
			cin>>a[i][j];
	cin>>b>>c;
	if(b>=0&&b<=4&&c>=0&&c<=4)
	{
		b++;
		c++;
		for(i=1;i<=5;i++)
		{
			d=a[b][i];
			a[b][i]=a[c][i];
			a[c][i]=d;
		}
		for(i=1;i<=5;i++)
		{
			for(j=1;j<=5;j++)
				cout<<setw(4)<<a[i][j];
			cout<<endl;
		}
	}
	else cout<<"error"<<endl;
    return 0;
}