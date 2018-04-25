#include<iostream>
#include<cstring>
#include<string>
using namespace std;

void turn(char &ch)
{
	if(ch>='F'&&ch<='Z')ch-=5;
	else if(ch>='A'&&ch<='E')ch+=21;
}

class codestring:public string
{
public:
	codestring(const string str):string(str){};
	string decode()
	{
		string str=*this;
		int length=str.length();
		for(int i=0;i<length;i++)
			turn(str[i]);
		return str;
	}
};

int main()
{
	char ch[300];
	string str;
	while(cin.getline(ch,300,'\n'))
	{
		str=string(ch);
		if(str=="ENDOFINPUT")return 0;
		if(str!="START"&&str!="END")cout<<codestring(str).decode()<<endl;
	}
}