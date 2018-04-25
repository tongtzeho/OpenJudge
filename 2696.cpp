#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,a,b,i,result;
	char c[6];
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a>>c>>b;
		if (c[2]=='l') result=a*b;
		else if (c[2]=='v') result=a/b;
		else if (c[2]=='b') result=a-b;
		else if (c[0]=='a') result=a+b;
		else result=a%b;
		cout<<result<<endl;
	}
	return 0;
}