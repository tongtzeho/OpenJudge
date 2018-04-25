#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int len(char c[ ])
{
	int n=0;
	while(1==1)
	{
		if (c[n]!='\0'&&c[n]!=13) n++;
		else return n;
	}
}
int main()
{
	char word[500],longest[500],ch,input[500];
	int i,j,k=0,lo=0;
	for(i=0;i<500;i++)
		word[i]='\0';
	while(cin.get(ch))
	{
		if ((int(ch)>=65&&int(ch)<=90)||(int(ch)>=97&&int(ch)<=122))
		{
			word[k]=ch;
			k++;
		}
		else
		{
			k=0;
			if(len(word)>=lo)
			{
				lo=len(word);
				for(i=0;i<lo;i++)
					longest[i]=word[i];
			}
			word[lo-1]='\0';
		}
		if (ch==10)
		{
			k=0;
			for(i=0;i<lo;i++)
			{
			    cout<<longest[i];
			    longest[i]='\0';
			}
		    cout<<endl;
			for(i=0;i<500;i++)
		        word[i]='\0';
			lo=0;
		}
	}
	return 0;
}