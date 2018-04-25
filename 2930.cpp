#include<iostream>
using namespace std;
int main()
{
	char ch1,ch2;
	int a,b,i;
	while(cin>>a)
	{
		cin>>ch1;
		if(ch1!='!')cin>>b;
		if(ch1=='+')cout<<a+b<<endl;
		if(ch1=='-')cout<<a-b<<endl;
		if(ch1=='*')cout<<a*b<<endl;
		if(ch1=='/'&&b!=0)cout<<a/b<<endl;
		if(ch1=='%'&&b!=0)cout<<a%b<<endl;
		if((ch1=='/'||ch1=='%')&&b==0)cout<<"error\n";
		if(ch1=='!')
		{
			b=1;
			for(i=1;i<=a;i++)
				b*=i;
			cout<<b<<endl;
		}
	}
	return 0;
}