#include<iostream>
#include<cstring>
#include<string>
using namespace std;
bool cmp(char c1,char c2)
{
	if(c1>='A'&&c1<='Z')c1-=('A'-'a');
	if(c2=='2'&&c1>='a'&&c1<='c')return 1;
	else if(c2=='3'&&c1>='d'&&c1<='f')return 1;
	else if(c2=='4'&&c1>='g'&&c1<='i')return 1;
	else if(c2=='5'&&c1>='j'&&c1<='l')return 1;
	else if(c2=='6'&&c1>='m'&&c1<='o')return 1;
	else if(c2=='7'&&c1>='p'&&c1<='s')return 1;
	else if(c2=='8'&&c1>='t'&&c1<='v')return 1;
	else if(c2=='9'&&c1>='w'&&c1<='z')return 1;
	return 0;
}
bool cmp(string st1,string st2)
{
	if(st1.length()!=st2.length())return 0;
	int i;
	for(i=0;i<st1.length();i++)
		if(!cmp(st1[i],st2[i]))return 0;
	return 1;
}
int main()
{
	string st1,st2;
	int i,n;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>st1>>st2;
		if(cmp(st1,st2))cout<<"Y\n";
		else cout<<"N\n";
	}
	return 0;
}
