#include<iostream>
using namespace std;
int main()
{
	int temp1,temp2,i,n,k,a[3001]={0},t;
	while(cin>>n)
	{
		cin>>temp2;
		for(i=1;i<=n;i++)
			a[i]=0;
		t=1;
		for(i=2;i<=n;i++)
		{
			temp1=temp2;
			cin>>temp2;
			k=temp1>temp2?temp1-temp2:temp2-temp1;
			if(k<=0||k>=n)t=0;
			if(t==1)a[k]++;
			if(a[k]>1)t=0;
		}
		if(t==1)cout<<"Jolly\n";
		else cout<<"Not jolly\n";
	}
	return 0;
}