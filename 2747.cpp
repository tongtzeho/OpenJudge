#include<iostream>
using namespace std;
int main()
{
	int t,n,sum,i,j,k,a1,a2,a3;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n;
		sum=n*3/5*5;
		for(j=sum;j>=0;j-=5)
			for(a1=n;a1>=0;a1--)
				for(a2=n;a2>=0;a2--)
					if(a1+a2<=j&&j-a1-a2<=n)
					{
						a3=j-a1-a2;
						if((a1+a2)%2==0&&(a2+a3)%3==0)
						{
							cout<<j<<endl;
							goto next;
						}
					}
next:   continue;
	}
	return 0;
}
