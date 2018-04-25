#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int length,mem[260][260];
char str[260];

int f(const int x,const int y)
{
	if(x<0||y>=length)return 0;
	if(mem[x][y]!=-1)return mem[x][y];
	if(str[x]==str[y])
	{
		mem[x][y]=f(x-1,y+1)+1;
		return mem[x][y];
	}
	else
	{
		if(f(x-1,y)>f(x,y+1))mem[x][y]=f(x-1,y);
		else mem[x][y]=f(x,y+1);
		return mem[x][y];
	}
}

int main()
{
	int n,i,j,k,maxnum;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<260;j++)
			str[j]='\0';
		cin>>str;
		length=strlen(str);
		for(j=0;j<=length;j++)
			for(k=0;k<=length;k++)
				mem[j][k]=-1;
		maxnum=0;
		for(j=1;j<=length;j++)
		{
			if(f(j-1,j)*2>maxnum)maxnum=2*f(j-1,j);
			if(j>1&&f(j-2,j)*2+1>maxnum)maxnum=2*f(j-2,j)+1;
		}
		if(length==1)maxnum=1;
		cout<<length-maxnum<<endl;
	}
	return 0;
}