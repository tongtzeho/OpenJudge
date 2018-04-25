#include<iostream>
using namespace std;
int turn(int n,int a)
{
	int r=0,i=1;
	while(n>0)
	{
		if((n%10)>=a)
		{
			r=-1000;
			break;
		}
		r+=((n%10)*i);
		i*=a;
		n/=10;
	}
	return r;
}
int main()
{
	int p,q,r,i,j,n,k,p1,q1,r1;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>p>>q>>r;
		k=2;
		while(1==1)
		{
			p1=turn(p,k);
			q1=turn(q,k);
			r1=turn(r,k);
			//cout<<p1<<' '<<q1<<' '<<p1*q1<<' '<<r1<<' '<<k<<endl;
			if(p1==-1000||q1==-1000||r1==-1000)
			{
				k++;
				continue;
			}
			if(r<10&&k>10)
			{
				k=0;
				break;
			}
			if(p1*q1==r1)break;
			if(p1*q1<r1)
			{
				k=0;
				break;
			}
			k++;
		}
		cout<<k<<endl;
	}
	return 0;
}