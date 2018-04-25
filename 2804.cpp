#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
using namespace std;
struct ch
{
	char temp;
	char ch1[16];
	char ch2[16];
}
word[100001];
int cmp(const void *a, const void *b)
{
	return strcmp(((struct ch*)a)->ch2,((struct ch*)b)->ch2);
}
int main()
{
	int n=0,i;
	while(cin.get(word[n].temp)&&word[n].temp!=10)
	{
		scanf("%s%s",word[n].ch1,word[n].ch2);
		cin.get();
		n++;
	}
	qsort(word,n,sizeof(word[0]),cmp);
	char fwd[16];
	int a,b,t;
	while(scanf("%s",fwd)!=EOF)
	{
		a=0;
		b=n-1;
		while(strcmp(fwd,word[(a+b)/2].ch2)!=0&&a!=b)
		{
			if(strcmp(fwd,word[(a+b)/2].ch2)<0)b=(a+b)/2;
			else a=(a+b)/2==a?a+1:(a+b)/2;
		}
		if(strcmp(fwd,word[(a+b)/2].ch2)==0)printf("%c%s\n",word[(a+b)/2].temp,word[(a+b)/2].ch1);
		else printf("eh\n");
	}
	return 0;
}