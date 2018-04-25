#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	string sjname[12];
	int m,n,i,j,k,temp[12];
	int sjsum[12]={0},sjst[12]={0},sum[12]={0},s[12]={0};
	cin>>m>>n;
	for(i=1;i<=n;i++)
		cin>>sjname[i];
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>temp[j];
			if(temp[j]>0)
			{
				sjst[j]++;
				sjsum[j]+=temp[j];
			}
		}
		for(j=1;j<=n;j++)
		{
			if(temp[j]>0)
			    for(k=1;k<=n;k++)
				{
					if(temp[k]>0)
					{
						sum[j]+=temp[k];
						s[j]++;
					}
				}
		}
	}
	for(i=1;i<=n;i++)
		cout<<sjname[i]<<' '<<sum[i]/s[i]-sjsum[i]/sjst[i]<<endl;
	return 0;
}