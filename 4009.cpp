#include<iostream>
using namespace std;

short mem[2][8388609]={0},memcount[8388609]={0};

inline int intturn(const int x,const int k)
{
	return (x^(x>>1))%k;
}

inline short count(const int x,const int k)
{
	if(x>=8388609)return memcount[x%k]+1;
	if(memcount[x]!=0||x==0)return memcount[x];
	memcount[x]=memcount[x%k]+1;
	return memcount[x];
}

int main()
{
	int s[25]={0},i,j,k=1;
	short *p,r;
	for(i=1;i<=24;i++)
	{
		k*=2;
		for(j=0;j<k;j++)
		{
			if(i<24)p=&(mem[i%2][j]);
			else p=&r;
			*p=mem[(i+1)%2][intturn(j,k/2)]+count(j,k/2);
			if((*p)*4==i*(i+1))s[i]++;
		}
	}
	while(cin>>i)
	{
		if(i==0)return 0;
		cout<<i<<" "<<s[i]<<endl;
	}
}