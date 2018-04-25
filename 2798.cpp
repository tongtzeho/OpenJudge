#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	char input[12000],ch[10];
	int i,j,k,n,l;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>input;
		l=strlen(input);
		if(l%4!=0)
		{
			for(j=l+3+l%4;j>=4-l%4;j--)
				input[j]=input[j-4+l%4];
			for(j=0;j<4-l%4;j++)
				input[j]='0';
			l+=(4-l%4);
		}
		for(j=0;j<l/4;j++)
		{
			k=(input[4*j]-48)*8+(input[4*j+1]-48)*4+(input[4*j+2]-48)*2+input[4*j+3]-48;
			if(k>9)cout<<char(k+55);
			else cout<<k;
		}
		cout<<endl;
	}
	return 0;
}