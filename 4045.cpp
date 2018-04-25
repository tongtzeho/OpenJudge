#include<iostream>
using namespace std;
int main()
{
	int n,i,m,s,t;
	cin>>n;
	s=0;
	for(i=1;i<=n;i++)
	{
		m=i;
		if(m%3!=0&&m%5!=0)
		{
			t=1;
			while(m!=0)
			{
				if(m%10==3||m%10==5)
				{
					t=0;
					break;
				}
				m/=10;
			}
			if(t==1)s+=i*i;
		}
	}
	cout<<s;
	return 0;
}