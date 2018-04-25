#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	int total[27]={0},i,j;
	char ch;
	while(cin.get(ch))
	{
		if(ch>='a'&&ch<='z')total[ch-'a'+1]++;
	}
	for(i=1;i<=26;i++)
		for(j=1;j<=total[i];j++)
			cout<<char(i+'a'-1);
	return 0;
}