#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	char ch[50];
	int i,j,t1=0,t2=0,n=0,l;
	cin.getline(ch,40,'\n');
	l=strlen(ch);
	n=0;
	for(i=0;i<l;i++)
	{
		if(ch[i]>=48&&ch[i]<=57)
		{
			if(t1==0)t1=1;
			n*=10;
			n+=ch[i]-48;
		}
		else
		{
			if(t1==1)cout<<n<<endl;
			n=0;
			t1=0;
		}
	}
	if(t1==1)cout<<n<<endl;
	return 0;
}