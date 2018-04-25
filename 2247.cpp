#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	int i,j,k,l,s=0,num[10000]={0};
	string st[4]={"th","st","nd","rd"};
	double a=1,b,c,d,n;
	for(i=1;i<=31;i++)
	{
		b=1;
		for(j=1;j<=20;j++)
		{
			c=1;
			for(k=1;k<=15;k++)
			{
				d=1;
				for(l=1;l<=12;l++)
				{
					n=a*b*c*d;
					if(n>2000000000)break;
					num[s]=int(n);
					s++;
					d*=7;
				}
				c*=5;
				if(a*b*c>2000000000)break;
			}
			b*=3;
			if(a*b>2000000000)break;
		}
		a*=2;
		if(a>2000000000||a<0)break;
	}
	for(i=0;i<5842;i++)
		for(j=i+1;j<5842;j++)
			if(num[i]>num[j])
			{
				num[i]^=num[j];
				num[j]^=num[i];
				num[i]^=num[j];
			}
	while(cin>>k&&k!=0)
	{
		if(k%10==1&&k%100!=11)l=1;
		else if(k%10==2&&k%100!=12)l=2;
		else if(k%10==3&&k%100!=13)l=3;
		else l=0;
		cout<<"The "<<k<<st[l]<<" humble number is "<<num[k-1]<<".\n";
	}
	return 0;
}