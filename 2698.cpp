#include<iostream>
using namespace std;
int a[10]={0},b=0;
void next(int n)
{
	int i,j=a[n]+1,t;
	if(n==1)return;
	while(j<9)
	{
		t=1;
		for(i=1;i<=n-1;i++)
			if(a[i]==j||a[i]+i==j+n||a[i]-i==j-n)
			{
				t=0;
				break;
			}
		if(t==1)
		{
			a[n]=j;
			break;
		}
		j++;
	}
	if(j==9)
	{
		a[n]=0;
		next(n-1);
	}
	else if(n==8)
	{
		cout<<"No. "<<++b<<endl;
		for(i=1;i<=8;i++)
			for(j=1;j<=8;j++)
			{
				a[j]==i?cout<<1:cout<<0;
				j<8?cout<<' ':cout<<endl;
			}
		a[8]=0;
		next(7);
	}
	else next(n+1);
}
int main()
{
	int i;
	for(i=1;i<=8;i++)
	{
		a[1]=i;
		a[2]=a[3]=a[4]=a[5]=a[6]=a[7]=a[8]=0;
	    next(2);
	}
	return 0;
}