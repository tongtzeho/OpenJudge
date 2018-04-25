#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	int TESTDATA,m,q,i,j,k,length,temp,total,n[101]={0};
	char s[101];
	cin>>TESTDATA;
	for(k=1;k<=TESTDATA;k++)
	{
		total=0;
		for(j=0;j<101;j++)
			s[j]='\0';
		cin>>s>>m>>q;
		length=strlen(s);
		for(i=0;i<=length-m;i++)
		{
			temp=0;
			for(j=i;j<i+m;j++)
				temp+=s[j]-'a'+1;
			if(temp==q)
			{
				total++;
				n[total]=i;
			}
		}
		cout<<total<<endl;
		for(i=1;i<=total;i++)
		{
			for(j=n[i];j<n[i]+m;j++)
				cout<<s[j];
			cout<<endl;
		}
	}
	return 0;
}