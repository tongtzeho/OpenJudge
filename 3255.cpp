#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int change14to10(char ch[ ])
{
	int m=1,s=0,p,j;
	for(j=strlen(ch)-1;j>=0;j--)
	{
		if(ch[j]<=57)p=ch[j]-48;
		else p=ch[j]-55;
		s+=p*m;
		m*=10;
	}
	return s;
}
void change10to6(int s)
{
	int j=0,a[300]={0};
	while(s!=0)
	{
		j++;
		a[j]=s%6;
		s/=6;
	}
	while(j>0)
	{
		cout<<a[j];
		j--;
	}
}
int main()
{
	int n,i;
	char ch[100];
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ch;
		if(ch[0]=='-'||ch[0]=='0')
		{
			cout<<ch[0];
			ch[0]='0';
		}
		change10to6(change14to10(ch));
		cout<<endl;
	}
	return 0;
}