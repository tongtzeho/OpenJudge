#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	int num[30][400]={0},i,j,k,l,sta[30]={0},max=0;
	char input[90];
	while(cin>>input&&input[0]!='3')
	{
		l=strlen(input);
		for(i=0;i<l;i++)
		{
			k=input[i]-64;
			if(k<0||k>28)k=0;
			sta[k]++;
			if(sta[k]>max&&k!=0)max=sta[k];
			num[k][sta[k]]=1;
		}
	}
	for(i=max;i>=1;i--)
	{
		for(j=1;j<=26;j++)
		{
			if(num[j][i]==1)cout<<'*';
			else cout<<' ';
			if(j<26)cout<<' ';
		}
		cout<<endl;
	}
	for(i=65;i<=90;i++)
	{
		cout<<char(i);
		if(i<90)cout<<' ';
	}
	return 0;
}