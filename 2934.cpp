#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str[20],substr[5],output[25];
	int i,s;
	while(cin>>str>>substr)
	{
		s=0;
		for(i=0;i<strlen(str);i++)
			if(str[i]>str[s])s=i;
		for(i=0;i<=s;i++)
			output[i]=str[i];
		for(i=s+1;i<=s+3;i++)
			output[i]=substr[i-s-1];
		for(i=s+4;i<strlen(str)+3;i++)
			output[i]=str[i-3];
		for(i=0;i<strlen(str)+3;i++)
			cout<<output[i];
		cout<<endl;
	}
	return 0;
}