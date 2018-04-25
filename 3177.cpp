#include<iostream>
using namespace std;
bool ispri(const int x)
{
	if(x==1)return 0;
	if(x==2||x==3||x==5||x==7)return 1;
	if(x%2==0||x%3==0||x%5==0)return 0;
	for(int i=3;i*i<=x;i+=2)
		if(x%i==0)return 0;
	return 1;
}
int prinum(const int x,const int y)
{
	int r=0;
	for(int i=x;i<=y;i++)
		r+=ispri(i);
	return r;
}
int main()
{
	int x,y;
	cin>>x>>y;
	if(x<y)cout<<prinum(x,y);
	else cout<<prinum(y,x);
	return 0;
}