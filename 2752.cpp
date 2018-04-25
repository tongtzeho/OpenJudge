#include<iostream>
#include<cstring>
#include<string>
using namespace std;
bool cmp(char c1,char c2,string &mode)
{
	if(mode=="inc")return c1>c2;
	else if(mode=="dec")return c1<c2;
	else if(mode=="ncinc")
	{
		if(c1>='A')c1-=('A'-'a');
		if(c2>='A')c2-=('A'-'a');
		return c1>c2;
	}
	else
	{
		if(c1>='A')c1-=('A'-'a');
		if(c2>='A')c2-=('A'-'a');
		return c1<c2;
	}
}
int main()
{
	string mode;
	int i,j,order[2000],n;
	char st[2000][200];
	cin>>mode>>n;
	cin.get();
	for(i=1;i<=n;i++)
	{
		order[i]=i;
		cin.getline(st[i],200,'\n');
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(cmp(st[order[i]][0],st[order[j]][0],mode))
			{
				order[i]^=order[j];
				order[j]^=order[i];
				order[i]^=order[j];
			}
	for(i=1;i<=n;i++)
		cout<<st[order[i]]<<endl;
	return 0;
}