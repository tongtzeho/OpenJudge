#include<iostream>
using namespace std;
int a[110][110]={0},mem[110]={0},mem1[110]={0},time1[110][110]={0},tmax,p;
void checkall(int i)
{
	int j;
	for(j=1;j<=p;j++)
		if(a[i][j]>0&&mem1[j]==0)
		{
			mem1[j]=1;
			checkall(j);
		}
}
void delandnew(int i)
{
	int j,k,n;
	mem[i]=1;
	for(j=1;j<=p;j++)
	{
		time1[j][i]=-1;
		if(a[i][j]>0&&time1[i][j]!=-1)time1[i][j]=a[i][j];
	}
}
void passtime()
{
	int i,j,k,rei[12000]={0},s=0;
	tmax++;
	for(i=1;i<=p;i++)
		for(j=1;j<=p;j++)
		{
			if(time1[i][j]==1)
			{
				s++;
				rei[s]=j;
			}
			if(time1[i][j]>0)time1[i][j]--;
		}
	for(i=1;i<=s;i++)
		delandnew(rei[i]);
	for(i=1;i<=p;i++)
		if(mem[i]==0)
		{
			j=0;
			break;
		}
	if(j==0)passtime();
}
int main()
{
	int i,j,k,c,n,m,tmin[110],t,s;
	while(cin>>p&&p!=0)
	{
		for(i=0;i<=p+1;i++)
		{
			mem[i]=tmin[i]=0;
			for(j=0;j<=p+1;j++)
				a[i][j]=time1[i][j]=0;
		}
		for(i=1;i<=p;i++)
		{
			cin>>c;
			for(j=1;j<=c;j++)
			{
				cin>>k;
				cin>>a[i][k];
			}
		}
		for(i=1;i<=p;i++)
		{
			for(j=0;j<=p+1;j++)
				mem[j]=mem1[j]=0;
			s=0;
			mem[i]=mem1[i]=1;
			checkall(i);
			for(j=1;j<=p;j++)
				if(mem1[j]==0)
				{
					s=1;
					break;
				}
			if(s==1)continue;
			tmax=0;
			for(j=0;j<=p+1;j++)
				for(k=0;k<=p+1;k++)
					time1[j][k]=0;
			delandnew(i);
			passtime();
			tmin[i]=tmax;
		}
		k=0;
		t=2147481647;
		for(i=1;i<=p;i++)
			if(tmin[i]<t&&tmin[i]>0)
			{
				k=i;
				t=tmin[i];
			}
		if(k==0)cout<<"disjoint\n";
		else cout<<k<<' '<<t<<endl;
	}
	return 0;
}