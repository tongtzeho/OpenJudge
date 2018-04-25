#include<iostream>
#include<cstring>
#include<string>
using namespace std;
char change(char c)
{
	if(97<=c&&c<=122)return char(c-32);
	else return c;
}
int main()
{
	char ch[200];
	int i,j,k;
	cin.getline(ch,160);
	k=strlen(ch);
	ch[0]=change(ch[0]);
	cout<<ch[0];
	for(i=1;i<k;i++)
	{
		if(ch[i-1]==' '||ch[i-1]=='\t'||ch[i-1]=='\r'||ch[i-1]=='\n')ch[i]=change(ch[i]);
		cout<<ch[i];
	}
	return 0;
}
