#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,x[200],y[200],ymost[200]={0},xmost=0,i,j,b[200]={0},t=1;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		b[x[i]]=1;
		if (x[i]>xmost) xmost=x[i];
		if (y[i]>ymost[x[i]]) ymost[x[i]]=y[i];
	}
	for(i=0;i<=xmost;i++)
	{
		if(b[i]==0)continue;
		t=1;
		for(j=i+1;j<=xmost;j++)
		{
			if(b[j]==0)continue;
			if(ymost[j]>=ymost[i])
			{
				t=0;
				break;
			}
		}
		if(t==0)continue;
		else
		{
			cout<<'('<<i<<','<<ymost[i]<<')';
			if(i<xmost) cout<<',';
			continue;
		}
	}
	return 0;
}