#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	char c1[100],c2[100];
	int i,j;
	cin.getline(c1,90,'\n');
	cin.getline(c2,90,'\n');
	for(i=0;i<strlen(c1);i++)
		c1[i]=(c1[i]>=65&&c1[i]<=90)?char(c1[i]+32):c1[i];
	for(i=0;i<strlen(c2);i++)
		c2[i]=(c1[i]>=65&&c2[i]<=90)?char(c2[i]+32):c2[i];
	if(strcmp(c1,c2)>0)cout<<'>';
	else if(strcmp(c1,c2)==0)cout<<'=';
	else cout<<'<';
	return 0;
}