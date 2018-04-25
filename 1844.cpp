#include<iostream>
using namespace std;
int f(int x)
{
	int i=1,sum=0;
	if(x==1)return 1;
	while(1==1)
	{
		sum+=i;
		if((sum-x)%2==0&&(sum-x)>2) return i;
		i++;
	}
}
int main()
{
	int n;
	cin>>n;
	cout<<f(n);
	return 0;
}