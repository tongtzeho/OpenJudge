#include<iostream>
using namespace std;

bool next(const int t,int *b)
{
	int i,j;
	bool t2=0;
	if(b[0]==t&&b[t]==t)return 0;
	for(i=b[0];i>=1;i--)
		if(b[i]!=t+i-b[0])
		{
			t2=1;
			break;
		}
	if(!t2)
	{
		b[0]++;
		for(i=1;i<=b[0];i++)
			b[i]=i;
		return 1;
	}
	b[i]++;
	for(j=i+1;j<=t;j++)
		b[j]=b[j-1]+1;
	return 1;
}

int main()
{
	int n,i,s,a[13],t,b[13],c,m;
	while(cin>>n)
	{
		if(n==0)return 0;
		m=n;
		s=t=0;
		for(i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				t++;
				a[t]=i;
				while(n%i==0)
					n/=i;
			}
		}
		if(n!=1)
		{
			t++;
			a[t]=n;
		}
		b[0]=b[1]=1;
		do
		{
			c=1;
			for(i=1;i<=b[0];i++)
				c*=a[b[i]];
			if(b[0]%2==1)s+=(m/c-1);
			else s-=(m/c-1);
		}while(next(t,b));
		cout<<m-1-s<<endl;
	}
	return 0;
}