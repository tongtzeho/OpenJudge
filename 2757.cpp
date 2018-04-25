#include<iostream>
using namespace std;
int mem[2000]={0};
int f(int *a,int k,int n)
{
	if(mem[k]!=0)return mem[k];
	int i,d,max=0;
	for(i=k+1;i<=n;i++)
		if(a[i]>a[k])
		{
			d=f(a,i,n)+1;
			if(d>max)max=d;
		}
	mem[k]=(max!=0)?max:1;
	return mem[k];
}
int main()
{
	int n,i,*a,max=0;
	cin>>n;
	a=new int[n+1];
	a[0]=0;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		if(f(a,i,n)>max)max=f(a,i,n);
	cout<<max;
	return 0;
}