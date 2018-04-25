#include<iostream>
#include<cmath>
#define inf 2147480000
using namespace std;
bool mem1[1000][210][23];
int a[250],b[250],c[250],n,m,temp[30],ansa[30],ans=inf,ts,sum;
void f(int x,int y,int z)
{
	if(y>n||mem1[x+500][y][z])return;
	temp[z]=y;
	ts+=a[y]+b[y];
	int i;
	mem1[x+500][y][z]=1;
	if(z==m)
	{
		if(abs(x)<ans||(abs(x)==ans&&ts>sum))
		{
			ans=abs(x);
			for(i=1;i<=m;i++)
				ansa[i]=temp[i];
			sum=ts;
		}
	}
	else
	{
		for(i=y+1;i<=n;i++)
			f(x+a[i]-b[i],i,z+1);
	}
	ts-=(a[y]+b[y]);
}
int main()
{
	int i,j,k=0,l;
	while(cin>>n>>m)
	{
		ans=inf;
		ts=sum=0;
		k++;
		if(n==0&&m==0)return 0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i];
			c[i]=i;
		}
		for(i=1;i<1000;i++)
			for(j=0;j<=m;j++)
				for(l=0;l<=n;l++)
				    mem1[i][l][j]=0;
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				if(a[i]+b[i]<a[j]+b[j])
				{
					a[i]^=a[j];
					a[j]^=a[i];
					a[i]^=a[j];
					b[i]^=b[j];
					b[j]^=b[i];
					b[i]^=b[j];
					c[i]^=c[j];
					c[j]^=c[i];
					c[i]^=c[j];
				}
		for(i=1;i<=n;i++)
			f(a[i]-b[i],i,1);
		int d[30],s1=0,s2=0;
		for(i=1;i<=m;i++)
		{
			d[i]=c[ansa[i]];
			s1+=a[ansa[i]];
			s2+=b[ansa[i]];
		}
		cout<<"Jury #"<<k<<"\n";
		cout<<"Best jury has value "<<s1<<" for prosecution and value "<<s2<<" for defence:\n";
		for(i=1;i<=m;i++)
			for(j=i+1;j<=m;j++)
				if(d[i]>d[j])
				{
					d[i]^=d[j];
					d[j]^=d[i];
					d[i]^=d[j];
				}
		for(i=1;i<=m;i++)
			cout<<" "<<d[i];
		cout<<endl<<endl;
	}
	return 0;
}