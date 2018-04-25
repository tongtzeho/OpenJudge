#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	char ch[40];
	int i,j,k,l,temp,order[40]={0};
	while(cin>>ch)
	{
		cin>>k;
		l=strlen(ch);
		for(i=0;i<l;i++)
		{
			cin>>order[i];
			ch[i]=(ch[i]-65+k)%26+65;
		}
		for(i=0;i<l;i++)
			cout<<ch[order[i]-1];
		cout<<endl;
	}
	return 0;
}