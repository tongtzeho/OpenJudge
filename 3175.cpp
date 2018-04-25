#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double x,a,e,t;
	int n=1;
	cin>>x>>a>>e;
	t=a;
	if(x<0) x=-x;
	if(x==0) n=0;
	while(x>0)
	{
		if(x/t<e) 
		{
			n--;
			break;
		}
		else if(x/t==e) break;
		else
		{
			t*=a;
			n++;
		}
	}
	cout<<n;
	return 0;
}
