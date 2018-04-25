#include<iostream>
using namespace std;
int main()
{
	int n,i,a,b;
	while(1==1)
	{
		cin>>n;
		if(n==0)return 0;
		b=180*(n-2);
		for(i=1;i<n;i++)
		{
			cin>>a;
			b-=a;
		}
		cout<<b<<endl;
	}
}