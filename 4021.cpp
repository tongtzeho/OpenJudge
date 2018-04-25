#include<iostream>
using namespace std;
int main()
{
	int m,n,i,j,az,af1,af2,t,k,tz,d1,d2,t0;//af1最小负数 af2最大负数
	cin>>m;
	for(i=1;i<=m;i++)
	{
		cin>>n;
		az=100000000;
		af1=0;
		af2=-100000000;
		t=1;
		t0=0;
		tz=0;
		for(j=1;j<=n;j++)
		{
			cin>>k;
			if(j==1)d1=k;
			if(j==2)d2=k;
			if(k>0)tz=1;
			if(k==0)t0++;
			if(k<0)t*=-1;
			if(k>0&&k<az)az=k;
			if(k<0&&k>af2)af2=k;
			if(k<0&&k<af1)af1=k;
		}
		if(t0>1)cout<<d1<<endl;
		else if(t0==1&&t==1)cout<<0<<endl;
		else if(t0==1&&t==-1&&d1!=0)cout<<d1<<endl;
		else if(t0==1&&t==-1&&d1==0)cout<<d2<<endl;
		else if(t>0&&tz==1)cout<<az<<endl;
		else if(t>0&&tz==0)cout<<af1<<endl;
		else cout<<af2<<endl;
	}
	return 0;
}