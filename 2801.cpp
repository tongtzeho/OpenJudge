#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	int n,m,p,l,sum[200]={0},i,j,t=0;
	char ch[10000];
	cin>>n>>m>>p;
	for(i=1;i<=n;i++)
	{
		cin>>ch;
		for(j=0;j<m;j++)
			sum[ch[j]]++;
	}
	for(i=1;i<=p;i++)
	{
		cin>>ch;
		l=strlen(ch);
		for(j=0;j<l;j++)
			sum[ch[j]]--;
	}
	for(i=60;i<=100;i++)
		for(j=1;j<=sum[i];j++)
		{
			t=1;
			cout<<char(i);
		}
	if(t==0)cout<<endl;
	return 0;
}
