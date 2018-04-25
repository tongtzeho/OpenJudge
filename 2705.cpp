#include<iostream>
using namespace std;
inline int minnum(int x,int y)
{
	if(x<y)return x;
	return y;
}
int main()
{
	int n,m,i,j,k,t,a[100]={0};
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>m;
		for(j=1;j<=m;j++)
			cin>>a[j];
		a[m+1]=500;
		t=k=0;
		for(j=1;j<=m;j++)
		{
			if(t+a[j]-a[j-1]+3<=60)
			{
				t+=a[j]+3-a[j-1];
				k+=a[j]-a[j-1];
			}
			else break;
		}
		k+=minnum(60-t,a[j]-a[j-1]);
		cout<<k<<endl;
	}
	return 0;
}