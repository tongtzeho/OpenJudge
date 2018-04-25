#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	unsigned __int64 n,m;
	int i,j,k,l,T,mod3[70];
	char str[70];
	cin>>T;
	for(i=1;i<=T;i++)
	{
		cin>>str;
		m=1;
		n=0;
		l=strlen(str);
		for(j=l-1;j>=0;j--)
		{
			n+=(str[j]-'0')*m;
			m*=2;
		}
		k=0;
		while(n>0)
		{
			k++;
			mod3[k]=n%3;
			n/=3;
		}
		for(j=k;j>=1;j--)
			cout<<mod3[j];
		cout<<endl;
	}
	return 0;
}