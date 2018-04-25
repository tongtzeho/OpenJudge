#include<iostream>
using namespace std;
int main()
{
	int b[5][5]={0},a[5][5]={0},i,j,k,l,m,n,p,q,r,s,t,sum=40;
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			cin>>a[i][j];
	for(i=0;i<=3;i++)//左上
		for(j=0;j<=3;j++)//右上
			for(k=0;k<=3;k++)//右下
				for(l=0;l<=3;l++)//左下
				{
					m=(-a[2][2]-i-j-k-l+400)%4;//中
					p=(-a[1][2]-i-j-m+400)%4;//上
					q=(-a[2][3]-j-k-m+400)%4;//右
					r=(-a[3][2]-k-l-m+400)%4;//下
					s=(-a[2][1]-i-l-m+400)%4;//左
					t=((i+s+p+a[1][1])%4==0)+((j+p+q+a[1][3])%4==0)+((k+q+r+a[3][3])%4==0)+((l+r+s+a[3][1])%4==0);
					//cout<<i<<p<<j<<s<<m<<q<<l<<r<<k<<' '<<t<<endl;
					if(t==4&&i+j+k+l+m+p+q+r+s<sum)
					{
						b[1][1]=i;
						b[1][2]=p;
						b[1][3]=j;
						b[2][1]=s;
						b[2][2]=m;
						b[2][3]=q;
						b[3][1]=l;
						b[3][2]=r;
						b[3][3]=k;
						sum=i+j+k+l+m+p+q+r+s;
					}
				}
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			for(k=1;k<=b[i][j];k++)
			{
				cout<<i*3+j-3;
				sum--;
				if(sum>0)cout<<' ';
			}
	return 0;
}