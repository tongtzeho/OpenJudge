#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	long long a,j;
//	__int64 a,j;
	int n,i;
	bool t;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
	//	scanf("%I64u",&a);
		if(a%2==0&&a!=2)cout<<"2\n";
		else
		{
			t=0;
			for(j=3;j*j<=a;j+=2)
				if(a%j==0)
				{
					t=1;
					cout<<j<<endl;
				//	printf("%I64u\n",j);
					break;
				}
			if(!t)cout<<"Prime\n";
		}
	}
	return 0;
}