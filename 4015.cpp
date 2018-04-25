#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	char str[120];
	int i,l;
	bool t,t2,t3,correct;
	while(cin.getline(str,120,'\n'))
	{
		l=strlen(str);
		t=t2=t3=0;
		correct=1;
		for(i=0;i<l;i++)
		{
			if(!t&&str[i]!=' ')
			{
				t=1;
				if(str[i]=='.'||str[i]=='@')correct=0;
			}
			if(str[i]=='@')
			{
				if(!t2)t2=1;
				else correct=0;
				if((i+1<l&&str[i+1]=='.')||(i>0&&str[i-1]=='.'))correct=0;
			}
			if(str[i]=='.'&&t2)t3=1;
		}
		if(!t3)correct=0;
		if(str[l-1]=='.'||str[l-1]=='@')correct=0;
		correct?cout<<"YES\n":cout<<"NO\n";
	}
	return 0;
}