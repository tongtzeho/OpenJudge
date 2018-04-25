#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int mem[500][500]={0};
char ch1[500],ch2[500];
int f(int x,int y)
{
	if(x<0||y<0)return 0;
	if(mem[x][y]!=-1)return mem[x][y];
	if(ch1[x]==ch2[y])
	{
		mem[x][y]=f(x-1,y-1)+1;
		return mem[x][y];
	}
	else
	{
		if(f(x-1,y)>f(x,y-1))mem[x][y]=mem[x-1][y];
		else mem[x][y]=mem[x][y-1];
		return mem[x][y];
	}
}
int main()
{
	int i,j,l1,l2;
	while(cin>>ch1>>ch2)
	{
		l1=strlen(ch1);
		l2=strlen(ch2);
		for(i=0;i<l1;i++)
			for(j=0;j<l2;j++)
				mem[i][j]=-1;
		cout<<f(l1-1,l2-1)<<endl;
	}
	return 0;
}