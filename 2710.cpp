#include<iostream>
#include<cmath>
using namespace std;
int strlen(char ch[ ])
{
	int i=0;
	while(1==1)
	{
		i++;
		if (ch[i]=='\0') return i;
	}
}
int main( )
{
	int a,b,k,length,i=0,j,n=0,m=0,t=1;
	char c,str[34],str1[34];
	cin>>a>>str>>b;
	length=strlen(str);
	for (i=1;i<=length;i++)
	{
		if ((str[i-1]>=48)&&(str[i-1]<=57)) k=str[i-1]-48;
		else if ((str[i-1]>=65)&&(str[i-1]<=90)) k=str[i-1]-55;
		else if ((str[i-1]>=97)&&(str[i-1]<=122)) k=str[i-1]-87;
		m=length-i;
		t=1;
		for (j=1;j<=m;j++)
			t=t*a;
		n=n+k*t;
	}
	i=0;
	do
	{
		k=n%b;
		n=n/b;
		if ((k>=0)&&(k<=9)) str1[i]=k+48;
		else if (k>=10) str1[i]=k+55;
	    i++;
	} while (n!=0);
    for (j=i;j>=1;j=j-1)
		cout<<str1[j-1];
	return 0;
}
