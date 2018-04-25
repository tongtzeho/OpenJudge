#include<iostream>
using namespace std;
int ans[50]={0,1};
void calc()
{
	int i,t=0;
	for(i=1;i<=40;i++)
	{
		ans[i]=ans[i]*2+t;
		t=ans[i]/10;
		ans[i]%=10;
	}
}
int main()
{
	int m,i,j;
	cin>>m;
	for(i=1;i<=m;i++)
		calc();
	j=0;
	for(i=40;i>=1;i--)
	{
		if(ans[i]!=0)j=1;
		if(j==1)cout<<ans[i];
	}
	return 0;
}