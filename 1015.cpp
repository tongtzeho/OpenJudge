#include<iostream>
#include<cmath>
using namespace std;
int n,m,a[250],b[250],ans[30][1000][30],v[250],s[250],mem[30][1000];
bool t[250];
int main()
{
	int i,j,k,l,tests=0;
	while(cin>>n>>m)
	{
		tests++;
		if(n==0&&m==0)return 0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i];
			v[i]=a[i]-b[i];
			s[i]=a[i]+b[i];
		}
		for(i=0;i<=m;i++)
			for(j=0;j<1000;j++)
				mem[i][j]=-1;
		for(i=1;i<=m;i++)
		{
			if(i==1)
			{
				for(j=1;j<=n;j++)
					if(s[j]>mem[1][v[j]+500])
					{
						mem[1][v[j]+500]=s[j];
						ans[1][v[j]+500][1]=j;
					}
			}
			else
			{
				for(j=500-20*i;j<=500+20*i;j++)
				{
					if(mem[i-1][j]!=-1)
					{
						for(k=1;k<=n;k++)
							t[k]=0;
						for(k=1;k<i;k++)
							t[ans[i-1][j][k]]=1;
						for(k=1;k<=n;k++)
							if(!t[k]&&mem[i-1][j]+s[k]>mem[i][j+v[k]])
							{
								mem[i][j+v[k]]=mem[i-1][j]+s[k];
								for(l=1;l<i;l++)
									ans[i][j+v[k]][l]=ans[i-1][j][l];
								ans[i][j+v[k]][i]=k;
							}
					}
				}
			}
		}
		int s1=0,s2=0;
		for(i=0;i<=20*m;i++)
			if(mem[m][500+i]!=-1||mem[m][500-i]!=-1)
			{
				if(mem[m][500-i]>mem[m][500+i])l=500-i;
				else l=500+i;
				for(j=1;j<=m;j++)
				{
					s1+=(v[ans[m][l][j]]+s[ans[m][l][j]])/2;
					s2+=(s[ans[m][l][j]]-v[ans[m][l][j]])/2;
				}
				for(j=1;j<=m;j++)
					for(k=j+1;k<=m;k++)
						if(ans[m][l][j]>ans[m][l][k])
						{
							ans[m][l][j]^=ans[m][l][k];
							ans[m][l][k]^=ans[m][l][j];
							ans[m][l][j]^=ans[m][l][k];
						}
				cout<<"Jury #"<<tests<<"\n";
				cout<<"Best jury has value "<<s1<<" for prosecution and value "<<s2<<" for defence:\n";
				for(j=1;j<=m;j++)
					cout<<" "<<ans[m][l][j];
				cout<<endl<<endl;
				break;
			}
	}
	return 0;
}
