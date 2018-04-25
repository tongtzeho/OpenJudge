#include<iostream>
using namespace std;
struct data
{
	int a,b;
}
*g;
int n,sum=-1;
void jump(int pos)
{
	if(g[pos].b==0)
	{
		int posnext=pos+g[pos].a;
		if(g[pos].a==0)sum--;
		g[pos].b=1;
		if(posnext>n)
		{
			sum++;
			return;
		}
		else if(posnext<=0)
		{
			sum++;
			jump(0);
		}
		else
		{
			sum++;
			jump(posnext);
		}
	}
	else
	{
		if(pos==n)
		{
			sum+=2;
			return;
		}
		else
		{
			sum+=2;
			jump(pos+1);
		}
	}
}
int main()
{
	cin>>n;
	int i;
	g=new data[n+2];
	g[0].a=0;
	g[0].b=0;
	for(i=1;i<=n;i++)
	{
		cin>>g[i].a;
		g[i].b=0;
	}
	jump(0);
	cout<<sum;
	return 0;
}