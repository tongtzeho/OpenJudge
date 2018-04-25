#include<iostream>
using namespace std;

int a[30]={0},n,s=0;

void sum(const int x,const int y)
{
	if(y==0)s++;
	if(y<=0||x>=n)return;
	for(int i=x+1;i<=n;i++)
	    sum(i,y-a[i]);
}

int main()
{
	int i,m;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		sum(i,m-a[i]);
	cout<<s;
	return 0;
}