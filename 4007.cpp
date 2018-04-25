#include<iostream>
#include<cstring>
#include<string>
using namespace std;

const int MAX_INT=2147000000;
int mem[1003][1003],l1,l2;
string str1,str2;

inline int min(const int x,const int y,const int z)
{
	if(x<=y&&x<=z)return x;
	else if(y<=z&&y<=x)return y;
	else return z;
}

int f(const int x,const int y)
{
	if(x>l1||y>l2)return MAX_INT;
	if(mem[x][y]!=-1)return mem[x][y];
	if(y==l2)return l1-x;
	if(x==l1)return l2-y;
	mem[x][y]=min(1+f(x+1,y),1+f(x,y+1),(str1[x]!=str2[y])+f(x+1,y+1));
	return mem[x][y];
}

int main()
{
	int n,i,j,k;
	string strtemp;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>str1>>str2;
		if(str1==str2)cout<<0<<endl;
		else
		{
			l1=str1.length();
			l2=str2.length();
		    for(j=0;j<=l1;j++)
			    for(k=0;k<=l2;k++)
				    mem[j][k]=-1;
		    cout<<f(0,0)<<endl;
		}
	}
	return 0;
}