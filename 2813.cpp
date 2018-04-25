#include<iostream>
#include<cstring>
using namespace std;
int a[20]={0},b[20]={0};
int main()
{
	int t,n,i,j,k,l,s,m=100000,sum;
	char ch[20];
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n;
		for(j=0;j<20;j++)
			a[j]=b[j]=0;
		m=100000;
		sum=0;
		for(j=1;j<=n;j++)
		{
			cin>>ch;
			for(k=1;k<=n;k++)
			{
				a[j]*=2;
				a[j]+=(ch[k-1]=='y'?0:1);
			}
		}
		s=1;
		for(j=1;j<=n;j++)
			s*=2;
		for(b[1]=0;b[1]<s;b[1]++)
		{
			for(j=2;j<=n;j++)
				b[j]=(a[j-1]^b[j-1]^b[j-2]^(b[j-1]>>1)^(b[j-1]<<1))%s;
			if((b[n-1]^b[n]^(b[n]>>1)^(b[n]<<1)^a[n])%s==0)
			{
				sum=0;
				for(j=1;j<=n;j++)
					for(k=1;k<=n;k++)
						sum+=(1^(b[j]>>(k-1))+1)%2;
				if(sum<m)m=sum;
			}
		}
		m==100000?cout<<"inf\n":cout<<m<<endl;
	}
	return 0;
}