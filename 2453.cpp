#include<iostream>
using namespace std;
int main()
{
	char ch[22];
	int i,j,k,t,s,n;
	while(1==1)
	{
		cin>>n;
		if(n==0)return 0;
		k=0;
		t=0;
		s=-1;
		for(i=0;i<=21;i++)
		{
			ch[i]=n%2==0?'0':'1';
			n/=2;
			if(i>0&&t==0)
				if(ch[i]=='0'&&ch[i-1]=='1')
				{
					k=i;
					t=1;
				}
			if(t==0&&ch[i]=='1')s++;
		}
		ch[k]='1';
		for(i=0;i<=s-1;i++)
			ch[i]='1';
		for(i=s;i<k;i++)
			ch[i]='0';
		s=0;
		for(i=0;i<=21;i++)
		{
			t=1;
			if(ch[i]=='1')
			{
			    for(j=0;j<i;j++)
				    t*=2;
			    s+=t;
			}
		}
		cout<<s<<endl;
	}
}