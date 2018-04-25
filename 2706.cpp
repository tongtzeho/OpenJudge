#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
char ch[30][1001];
inline int log2(int x)
{
	return int(log(x)/log(2)+0.0000001);
}
void times(int x,int y,int z)
{
	char temp[1001],temp2[1001];
	int i,j,k,m,n,r;
	for(i=0;i<=600;i++)
		temp[i]=temp2[i]='0';
	for(i=0;i<=500;i++)//³ËÊý
	{
		m=ch[y][i]-48;
		k=0;
		for(j=0;j<=500-i;j++)//±»³ËÊý
		{
			n=ch[x][j]-48;
			r=m*n+k;
			k=r/10;
			r%=10;
			temp2[i+j]=r+48;
		}
		k=0;
		for(j=i;j<=500;j++)
		{
			m=temp[j]-48;
			n=temp2[j]-48;
			r=m+n+k;
			k=r/10;
			r%=10;
			temp[j]=r+48;
		}
	}
	for(i=0;i<=500;i++)
		ch[z][i]=temp[i];
}
int main()
{
	int n;
	cin>>n;
	cout<<int(n*log(2)/log(10)+1)<<endl;
	int i,j,num[30]={0},numsum=0,pow2[30]={1};
	for(i=1;i<=28;i++)
		pow2[i]=pow2[i-1]*2;
	ch[0][0]='2';
	for(i=1;i<=500;i++)
		ch[0][i]='0';
	for(i=0;i<=22;i++)
		times(i,i,i+1);
	j=n;
	while(j>0)
	{
		numsum++;
		num[numsum]=log2(j);
		j-=pow2[num[numsum]];
	}
	ch[29][0]='1';
	for(i=1;i<=500;i++)
		ch[29][i]='0';
	for(i=numsum;i>=1;i--)
		times(29,num[i],29);
	for(i=499;i>=1;i--)
	{
		cout<<ch[29][i];
		if(i%50==0)cout<<endl;
	}
	cout<<char(ch[29][i]-1);
	return 0;
}