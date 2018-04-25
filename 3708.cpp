#include<iostream>
#include<cmath>
using namespace std;
int main( )
{
	int n,total1=0,i,k,number;
	cin>>n;
	for(k=1;k<=n;k++)
	{
		total1=0;
		cin>>number;
		do
		{
		   i=number%2;
		   if (i==1) total1++;
		   number=number/2;
		} while (number>0);
		cout<<total1<<endl;
	}
	return 0;
}