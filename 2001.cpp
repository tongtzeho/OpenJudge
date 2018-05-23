#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int len[1001]={0},n=1;
char ch[1001][30],prev[1001][30];
bool cover(int i)
{
	int j,k,t;
	for(j=1;j<=n;j++)
	{
		if(len[j]<strlen(prev[i])||j==i)continue;
		t=0;
		for(k=0;k<strlen(prev[i]);k++)
			if(ch[j][k]!=prev[i][k])
			{
				t=1;
				break;
			}
		if(t==0)return t;
	}
	return t;
}
int main()
{
	int i,j,k,t;
	while(cin>>ch[n])
	{
		len[n]=strlen(ch[n]);
		n++;
	}
	n--;
	for(i=1;i<=n;i++)
	{
		t=0;
		for(j=0;j<len[i]-1;j++)
		{
			prev[i][j]=ch[i][j];
			if(cover(i))
			{
				t=1;
				break;
			}
		}
		if(t==0)prev[i][len[i]-1]=ch[i][len[i]-1];
		cout<<ch[i]<<' '<<prev[i]<<endl;
	}
	return 0;
}