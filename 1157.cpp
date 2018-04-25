#include<iostream>
#define MAX_NUM 103
#define inf 999999999
using namespace std;

int f,v;
int aes[MAX_NUM][MAX_NUM],mem[MAX_NUM][MAX_NUM];

int count(const int bunch,const int vase)
{
	int i,tmp,result=-inf;
	if(bunch>f||vase>v)
	{
		return 0;
	}
	else if(mem[bunch][vase]!=-inf)
	{
		return mem[bunch][vase];
	}
	for(i=vase+1;i<=v-f+bunch+1;i++)
		if((tmp=count(bunch+1,i))>result)
		{
			result=tmp;
		}
	mem[bunch][vase]=aes[bunch][vase]+result;
	return mem[bunch][vase];
}

int main()
{
	int i,j,tmp,answer=-inf;
	cin>>f>>v;
	for(i=1;i<=f;i++)
		for(j=1;j<=v;j++)
		{
			cin>>aes[i][j];
			mem[i][j]=-inf;
		}
	for(i=1;i<=v-f+1;i++)
		if((tmp=count(1,i))>answer)
		{
			answer=tmp;
		}
	cout<<answer;
	return 0;
}
