#include<iostream>
#include<cmath>
using namespace std;
bool viman(int i)
{
	int n=0,d=i;
	while(d>0)
	{
		n*=10;
		n+=d%10;
		d/=10;
	}
	if(n==i)
	{
		//cout<<i<<endl;
		return true;
	}
	return false;
}
bool ss(int i)
{
	int j;
	for(j=3;j<=sqrt(i);j+=2)
		if(i%j==0)return false;
	return true;
}
int main()
{
	int total[10001]={0},i,j,k,n;
	for(i=11;i<=10000;i++)
	{
		total[i]=total[i-1];
		if(viman(i)&&i%2==1)
		{
			if(ss(i))
				total[i]++;
		}
	}
	while(cin>>n)
		cout<<total[n]<<endl;
	return 0;
}