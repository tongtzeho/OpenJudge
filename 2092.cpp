#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int s[250001];
int main()
{
	vector<int> v;
	int n,m,i,j,maxnum,maxnum2,id,a[10001];
	while(cin>>n>>m)
	{
		if(n==0&&m==0)return 0;
		for(i=0;i<=10000;i++)
			a[i]=0;
		for(i=0;i<=250000;i++)
			s[i]=0;
		maxnum=0;
		v.clear();
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				scanf("%d",&id);
				s[a[id]]--;
				a[id]++;
				s[a[id]]++;
				if(a[id]>maxnum)maxnum=a[id];
			}
		for(i=maxnum-1; ;i--)
			if(s[i])
			{
				maxnum2=i;
				break;
			}
		for(i=0;i<=10000;i++)
			if(a[i]==maxnum2)v.push_back(i);
		sort(v.begin(),v.end());
		for(i=0;i<v.size();i++)
		{
			printf("%d",v[i]);
			if(i!=v.size()-1)printf(" ");
			else printf("\n");
		}
	}
}