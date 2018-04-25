#include <iostream>
using namespace std;

int weight[103],n,ans=-1;
unsigned char mem[52][52][62]={0};

void f(const int hn,const int ln,const int w)
{
	int z1=w/8,z2=w%8;
	if(mem[hn][ln][z1]&(1<<z2))return;
	if(hn+ln==n)
	{
		if(ans==-1)ans=w;
		else if(w<ans)ans=w;
	}
	else
	{
		if(hn+1<=(n+1)/2&&w+weight[hn+ln+1]<=480)f(hn+1,ln,w+weight[hn+ln+1]);
		if(ln+1<=(n+1)/2)
		{
			int tmp=w-weight[hn+ln+1];
			if(tmp>=0)f(hn,ln+1,tmp);
			else f(ln+1,hn,-tmp);
		}
	}
	mem[hn][ln][z1]|=(1<<z2);
}

int main()
{
	int total=0,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>weight[i];
		total+=weight[i];
	}
	f(0,0,0);
	cout<<(total-ans)/2<<" "<<(total+ans)/2<<endl;
	return 0;
}