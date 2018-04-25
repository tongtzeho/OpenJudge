#include<iostream>
using namespace std;
int mem[1000010]={0,1,2,0,0};
int pell(int n)
{
	if(mem[n]!=0)return mem[n];
	int result;
	result=(2*pell(n-1)+pell(n-2))%32767;
	mem[n]=result;
	return mem[n];
}
int main()
{
	int n,i,k,m=3,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>k;
		for(j=m;j<=k;j+=2)
			pell(j);
		if(k>m)m=k;
		cout<<pell(k)<<endl;
	}
	return 0;
}