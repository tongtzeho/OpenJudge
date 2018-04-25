#include<iostream>
using namespace std;
int main()
{
	char temp;
	cin.get();
	cin.get();
	while(cin.get(temp))
	{
		if((temp>=65&&temp<=89)||(temp>=97&&temp<=121))cout<<char(temp+1);
		else if(temp==90||temp==122)cout<<char(temp-25);
		else cout<<temp;
	}
	return 0;
}