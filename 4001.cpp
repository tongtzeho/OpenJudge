#include<iostream>
using namespace std;
int a[100001]={0},search[2][40000]={0};
int main()
{
	int n,k,i,j,minute=0,s=1,t=0;
	cin>>n>>k;
	a[n]=1;
	search[0][1]=n;
	while(a[k]==0)
	{
		t=0;
		for(i=1;i<=s;i++)
		{
			if(search[minute%2][i]-1>=0&&a[search[minute%2][i]-1]==0)
			{
				t++;
				search[(minute+1)%2][t]=search[minute%2][i]-1;
				a[search[minute%2][i]-1]=1;
			}
			if(search[minute%2][i]<k&&search[minute%2][i]+1<=100000&&a[search[minute%2][i]+1]==0)
			{
				t++;
				search[(minute+1)%2][t]=search[minute%2][i]+1;
				a[search[minute%2][i]+1]=1;
			}
			if(search[minute%2][i]<k&&search[minute%2][i]*2<=100000&&a[search[minute%2][i]*2]==0)
			{
				t++;
				search[(minute+1)%2][t]=search[minute%2][i]*2;
				a[search[minute%2][i]*2]=1;
			}
		}
		minute++;
		s=t;
	}
	cout<<minute;
	return 0;
}