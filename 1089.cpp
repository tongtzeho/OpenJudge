#include<iostream>
using namespace std;
int m[1000001]={0};
int main()
{
	int a,b,n,i,max=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a>>b;
		if(m[a]<b)m[a]=b;
		if(b>max)max=b;
	}
	a=b=0;
	for(i=1;i<=max;i++)
	{
		if(a==0&&m[i]!=0)a=i;
		if(b==0&&m[i]!=0)b=m[i];
		if(m[i]!=0)
		{
			if(i>b)
			{
				cout<<a<<" "<<b<<endl;
				a=i;
				b=m[i];
			}
			else if(m[i]>b)b=m[i];
		}
	}
	cout<<a<<" "<<b<<endl;
	return 0;
}
