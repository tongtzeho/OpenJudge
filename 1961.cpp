#include<iostream>
#include<cstdio>
#include<string>
#define MAX_LENGTH 1000003
using namespace std;
string p;
int next[MAX_LENGTH];
void calcnext()
{
	int j=0,k=-1,m=p.length();
	next[j]=k;
	while(j<m)
	{
		while(k>=0&&p[j]!=p[k])
			k=next[k];
		j++;
		k++;
		next[j]=k;
	}
}
int main()
{
	int i,l,testcase=0;
	while(cin>>l)
	{
		if(l==0)return 0;
		testcase++;
		cin>>p;
		p+='*';
		calcnext();
		printf("Test case #%d\n",testcase);
		for(i=2;i<=l;i++)
			if(i!=next[i]&&i%(i-next[i])==0&&i/(i-next[i])>1)printf("%d %d\n",i,i/(i-next[i]));
		printf("\n");
	}
}
