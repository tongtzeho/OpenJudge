#include<iostream>
#include<cmath>
using namespace std;
int main( )
{
	int n,i,k=10,a[101],b[11];
	while(cin>>b[1]>>b[2]>>b[3]>>b[4]>>b[5]>>b[6]>>b[7]>>b[8]>>b[9]>>b[10])
	{
	k=10;
	for(i=0;i<=100;i++)
		a[i]=0;
	for(i=1;i<=10;i++)
		a[b[i]]++;
	for(i=99;i>=1;i-=2)
		for(n=a[i];n>=1;n--)
		{
			cout<<i;
			k--;
			if(k>=1)cout<<' ';
		}
	for(i=0;i<=100;i+=2)
		for(n=a[i];n>=1;n--)
        {
			cout<<i;
			k--;
			if(k>=1)cout<<' ';
		}
	cout<<endl;
	}
	return 0;
}
