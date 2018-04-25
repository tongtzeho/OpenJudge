#include<iostream>
using namespace std;
int calc(int a,char c,int b)
{
	if(c=='+')return a+b;
	if(c=='-')return a-b;
}
int main()
{
	int a,b;
	char c;
	while(cin>>a>>c>>b)
		cout<<calc(a,c,b)<<endl;
	return 0;
}