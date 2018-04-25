#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	char input[1200];
	int i,j,k,l;
	while(cin>>input)
	{
		l=strlen(input);
		if(l==1&&input[0]=='0')return 0;
		k=0;
		for(i=0;i<l;i++)
		{
			k+=input[i]-48;
			k%=9;
		}
		if(k==0)k=9;
		cout<<k<<endl;
	}
}