#include<iostream>
using namespace std;
bool ugly(int i)
{
	if(i==1)return true;
	while(i%2==0)i/=2;
	while(i%3==0)i/=3;
	while(i%5==0)i/=5;
	if(i==1)return true;
	return false;
}
int min1(int x,int y,int z)
{
	if(x<y&&x<z)return 1;
	if(y<x&&y<z)return 2;
	if(z<x&&z<y)return 3;
	return 0;
}
int main()
{
	int b[2000]={0,1,2,3,4,5,6,8,9,10,12,15,16,18,20,24,25,27},j,k,n,max=17,c[5]={0,16,9,25},t,min,t2,t3,t5,t0,x,y,z,m;
	k=1;
	while(cin>>n)
	{
		if(n==0)return 0;
		if(n<=max)cout<<b[n]<<endl;
		else
		{
			for(j=max;j<=n;j++)
			{
		        min=1;
				t=0;
				for(k=j-2;k>=2;k--)
				    if(b[j-1]%b[k]==0)
					{
				    	if(t==0)min=k;
				    	if(t==1&&double(b[k+1])/b[k]<double(b[min+1])/b[min])min=k;
				    	if(b[k+1]-b[k]==1)break;
				    	t=1;
					}
		        b[j]=b[j-1]/b[min]*b[min+1];
				if(t0==1)
				{
					for(k=b[j-1]+1; ;k++)
						if(ugly(k))
						{
							b[j]=k;
							break;
						}
				}
				t0=t2=t3=t5=0;
				if(c[1]*2==b[j])
				{
					c[1]*=2;
					t0=1;
				}
				if(c[2]*3==b[j])
				{
					c[2]*=3;
					t0=1;
				}
				if(c[3]*5==b[j])
				{
					c[3]*=5;
					t0=1;
				}
		        if(c[1]*2<b[j]&&c[1]*2>b[j-1])t0=t2=1;
				if(c[2]*3<b[j]&&c[2]*3>b[j-1])t0=t3=1;
				if(c[3]*5<b[j]&&c[3]*5>b[j-1])t0=t5=1;
				if(t2+t3+t5>=1)
				{
					x=t2==1?c[1]*2:2147481600;
					y=t3==1?c[2]*3:2147481601;
					z=t5==1?c[3]*5:2147481602;
					m=min1(x,y,z);
					c[m]*=(m*2-m/2);
					b[j]=c[m];
				}
			}
			cout<<b[n]<<endl;
			max=n;
		}
	}
}
