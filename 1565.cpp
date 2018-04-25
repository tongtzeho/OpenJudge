#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	char input[40];
	int length,i,n,k;
	while(cin>>input&&input[0]!='0')
	{
		length=strlen(input);
		n=0;
		k=1;
		for(i=length-1;i>=0;i--)
		{
			k*=2;
			n+=(input[i]-48)*(k-1);
		}
		cout<<n<<endl;
	}
	return 0;
}