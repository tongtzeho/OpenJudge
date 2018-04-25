#include<iostream>
using namespace std;
int main()
{
	int n,i,j,t,sum=0,input,k;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		t=0;
		k=255;
		for(j=1;j<=n;j++)
		{
			cin>>input;
			if(input==0)t=k==0?0:(t+1)%2;
			if(input==255&&t==1)sum++;
			k=input;
		}
	}
	cout<<sum;
	return 0;
}