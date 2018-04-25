#include<iostream>
using namespace std;
int cl[10000000]={0,1,2,0,3};
int cyclelength(int n)
{
	if(n<10000000&&cl[n]!=0)return cl[n];
	int result;
	if(n%2==0)result=cyclelength(n/2)+1;
	else result=cyclelength(3*n+1)+1;
	if(n<10000000)cl[n]=result;
	return result;
}
int main()
{
	int i,j,max,n;
	while(cin>>i>>j)
	{
		cout<<i<<' '<<j<<' ';
		if(i>j)
		{
			max=i;
			i=j;
			j=max;
		}
		max=0;
		for(n=i;n<=j;n++)
			if(cyclelength(n)>max)max=cyclelength(n);
		cout<<max<<endl;
	}
	return 0;
}