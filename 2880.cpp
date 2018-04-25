#include<iostream>
#include<cmath>
using namespace std;
int len(char c[ ])
{
	int n=0;
	while(1==1)
	{
		if (c[n]!='\0') n++;
		else return n;
	}
}
int main()
{
	char word[500],longest[500];
	int i,j,lo=0;
	while(cin>>word)
	{
		if(len(word)>=lo)
		{
			lo=len(word);
			for(i=0;i<lo;i++)
				longest[i]=word[i];
		}
	}
	cout<<longest;
	return 0;
}