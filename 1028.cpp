#include<iostream>
#include<cstring>
#include<string>
#define AboutBlank "Ignored"
using namespace std;
int main()
{
	string web[200],input;
	int sum=1,i,j,k=1;
	web[1]="http://www.acm.org/";
	while(cin>>input)
	{
		if(input=="VISIT")
		{
			k++;
			sum=k;
			cin>>web[k];
			cout<<web[k]<<endl;
		}
		else if(input=="BACK")
		{
			if(k>1)
			{
				k--;
				cout<<web[k]<<endl;
			}
			else cout<<AboutBlank<<endl;
		}
		else if(input=="FORWARD")
		{
			if(k<sum)
			{
				k++;
				cout<<web[k]<<endl;
			}
			else cout<<AboutBlank<<endl;
		}
		else return 0;
	}
}