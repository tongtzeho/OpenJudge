#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int r1,c1,r2,c2,order[24],p1[24][24],p2[24][24],m[24];
bool ans=0;

bool next()
{
	int i,j,k,l;
	bool tmp[24]={0};
	for(i=1;i<=c1;i++)
		tmp[order[i]]=1;
	for(i=c1;i>=1;i--)
	{
		for(j=order[i]+1;j<=c2;j++)
		{
			if(!tmp[j])
			{
				tmp[order[i]]=0;
				tmp[j]=1;
				order[i]=j;
				l=j+1;
				for(k=i+1;k<=c1;k++)
					tmp[order[k]]=0;
				for(k=i+1;k<=c1;k++)
				{
					while(tmp[l])
						l++;
					order[k]=l;
					l++;
				}
				return 1;
			}
		}
	}
	return 0;
}

bool select(int i,int k)
{
	int j;
	for(j=1;j<=c1;j++)
		if(p1[i][j]!=p2[k][order[j]])return 0;
	return 1;
}

void calc()
{
	int i,k=0;
	for(i=1;i<=r1;i++)
	{
		k++;
		while(!select(i,k))
		{
			k++;
			if(r2-k<r1-i)return;
		}
	}
	ans=1;
}

int main()
{
	int i,j,k;
	string st;
	for(i=0;i<24;i++)
		for(j=0;j<24;j++)
			p1[i][j]=p2[i][j]=-1;
	cin>>r1>>c1;
	for(i=1;i<=r1;i++)
	{
		cin>>st;
		for(j=1;j<c1;j++)
		{
			if(st[j-1]=='1')p1[i][j]=1;
			else p1[i][j]=0;
		}
	}
	cin>>r2>>c2;
	for(i=1;i<=r2;i++)
	{
		cin>>st;
		for(j=1;j<c2;j++)
		{
			if(st[j-1]=='1')p2[i][j]=1;
			else p2[i][j]=0;
		}
	}
	for(i=1;i<=c1;i++)
		order[i]=i;
	do
	{
		calc();
		if(ans)
		{
			cout<<"Yes\n";
			return 0;
		}
	}
	while(next());
	cout<<"No\n";
	return 0;
}