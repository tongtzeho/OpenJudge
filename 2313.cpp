#include<iostream>
#include<cmath>
using namespace std;
int m[11000]={0};
int max(int x,int y)
{
	if(x>y)return x;
	return y;
}
int min(int x,int y)
{
	if(x<y)return x;
	return y;
}
int main()
{
	int i,j,n,a,b,c,d,s=0,t[11000]={0};
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>m[i];
	m[n+1]=m[n];
	t[0]=t[1]=m[1];
	for(i=2;i<=n;i++)
	{
		t[i]=t[i-1];
		if(t[i]<=min(m[i],m[i+1]))t[i]=min(m[i],m[i+1]);
		if(t[i]>=max(m[i],m[i+1]))t[i]=max(m[i],m[i+1]);
	}
	for(i=1;i<=n;i++)
		s+=abs(m[i]-t[i])+abs(t[i]-t[i-1]);
	cout<<s<<endl;
	return 0;
}