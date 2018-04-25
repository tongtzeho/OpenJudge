#include<iostream>
#include<cstring>
#include<string>
using namespace std;

inline int chartoint(const char ch)
{
	if(ch>='0'&&ch<='9')return ch-'0';
	else return ch-'A'+10;
}

int main()
{
	int n,m,i,j,k,l;
	char str[12];
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<12;j++)
			str[j]='\0';
		cin>>str;
		l=strlen(str);
		k=1;
		m=0;
		for(j=l-1;j>=0;j--)
		{
			m+=k*chartoint(str[j]);
			k*=16;
		}
		cout<<m<<endl;
	}
	return 0;
}