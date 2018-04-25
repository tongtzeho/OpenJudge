#include<iostream>
#include<cstring>
using namespace std;
int mem[1100]={1,2011,0,0};
int f2011(int x)
{
	if(mem[x]!=0)return mem[x];
	int result;
	result=(f2011(x-1)*2011)%10000;
	mem[x]=result;
	return mem[x];
}
int main()
{
	int k,n,i;
	cin>>k;
	char ch[300];
	for(i=1;i<=k;i++)
	{
		cin>>ch;
		if(strlen(ch)==1)n=ch[0]-48;
		else if(strlen(ch)==2)n=10*(ch[0]-48)+ch[1]-48;
		else if(strlen(ch)==3)n=100*(ch[0]-48)+10*(ch[1]-48)+ch[2]-48;
		else n=100*(ch[strlen(ch)-3]-48)+10*(ch[strlen(ch)-2]-48)+ch[strlen(ch)-1]-48;
		cout<<f2011(n)<<endl;
	}
	return 0;
}