#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	char input[70],result[70],temp[70];
	int lresult,ltemp,t,i,j,k,m,n,a,b,c,t1;
	while(cin>>input)
	{
		n=strlen(input);
		for(i=0;i<n;i++)
			temp[i]=result[i]=input[n-i-1];
		for(i=n;i<70;i++)
			temp[i]=result[i]='0';
		i=n;
		while(temp[i]=='0')
			i--;
		ltemp=i+1;
		for(i=1;i<=n;i++)
		{
			t=t1=0;
			for(j=0;j<=n;j++)
			{
				a=temp[j]-48;
				b=result[j]-48;
				c=a+b+t;
				t=c/10;
				c%=10;
				result[j]=c+48;
			}
			j=n;
			while(result[j]=='0')
				j--;
			lresult=j+1;
			if(lresult>n)
			{
				cout<<input;
				t1=1;
				cout<<" is not cyclic\n";
				break;
			}
			for(j=1;j<n&&i!=9;j++)
			{
				k=t=0;
				while(result[j+k]==temp[k])
				{
					k++;
					if(j+k==n)
					{
						t=1;
						break;
					}
				}
				m=0;
				if(t==1)
				{
					t=0;
				    while(result[m]==temp[k+m])
					{
					    m++;
					    if(k+m==n)
						{
							t=1;
							break;
						}
					}
				}
				if(t==1)break;
			}
			if(t==1)
			{
				cout<<input;
				cout<<" is cyclic\n";
				t1=1;
				break;
			}
		}
		if(t1==0)
		{
			cout<<input;
			t1=1;
			cout<<" is not cyclic\n";
		}
	}
	return 0;
}