#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char st[100];
	int i;
	while(cin.getline(st,90,'\n'))
	{
		cout<<st[0];
		for(i=1;i<strlen(st);i++)
			cout<<' '<<st[i];
		cout<<endl;
	}
	return 0;
}