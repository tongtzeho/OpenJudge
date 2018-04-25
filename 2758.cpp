#include<iostream>
using namespace std;
int mem[1000003]={0,1,1,2,3,5,8,13,21,34,55,89,0};
int fb(int a)
{
	if(mem[a]>0)return mem[a];
	int result;
	result=mem[a]=(fb(a-1)+fb(a-2))%1000;
	return result;
}
int main()
{
	int n,a,i,j,max=7;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		for(j=max;j<=a;j++)
			fb(j);
		if(a>max)max=a;
		cout<<fb(a)<<endl;
	}
	return 0;
}