#include<iostream>
using namespace std;
int a[503][503],b[260000],d[260000],mem[503][503]={0};
int max(int a,int b,int c,int d)
{
	int result=a>b?a:b;
	if(c>result) result=c;
	if(d>result) result=d;
	return result;
}
int sum(int i,int j)
{
    int result=0,p=0,q=0,r=0,s=0;
	if(mem[i][j]!=0) result=mem[i][j];
	else
	{
	    if(a[i][j]>a[i-1][j]) p=sum(i-1,j);
	    if(a[i][j]>a[i+1][j]) q=sum(i+1,j);
	    if(a[i][j]>a[i][j-1]) r=sum(i,j-1);
	    if(a[i][j]>a[i][j+1]) s=sum(i,j+1);
	    result=max(p,q,r,s)+1;
		mem[i][j]=result;
	}
	return result;
}
int main()
{
	int r,c,i,j,m=0,s=1;
	cin>>r>>c;
	for(i=0;i<=r+1;i++)
		a[i][0]=a[i][c+1]=2000000;
	for(j=0;j<=c+1;j++)
		a[0][j]=a[r+1][j]=2000000;
	for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)
		{
			cin>>a[i][j];
			if((i>=2)&&((a[i-2][j]<=a[i-1][j]||a[i-2][j]==2000000)+(a[i][j]<=a[i-1][j])+(a[i-1][j+1]<=a[i-1][j]||a[i-1][j+1]==2000000)+(a[i-1][j-1]<=a[i-1][j]||a[i-1][j+1]==2000000)+(a[i-2][j]<a[i-1][j]||a[i-2][j]==2000000)+(a[i][j]<a[i-1][j])+(a[i-1][j+1]<a[i-1][j]||a[i-1][j+1]==2000000)+(a[i-1][j-1]<a[i-1][j]||a[i-1][j+1]==2000000)>=5))
			{
				m++;
				b[m]=i-1;
				d[m]=j;
			}
		}
	for(j=1;j<=c;j++)
		if((a[r][j]>=a[r-1][j]||a[r-1][j]==2000000)+(a[r][j]>=a[r][j-1]||a[r][j-1]==2000000)+(a[r][j]>=a[r][j+1]||a[r][j+1]==2000000)+(a[r][j]>a[r-1][j]||a[r-1][j]==2000000)+(a[r][j]>a[r][j-1]||a[r][j-1]==2000000)+(a[r][j]>a[r][j+1]||a[r][j+1]==2000000)>=4)
		{
			m++;
			b[m]=r;
			d[m]=j;
		}
	for(i=1;i<=m;i++)
		if (sum(b[i],d[i])>s) s=sum(b[i],d[i]);
	cout<<s;
	return 0;
}
