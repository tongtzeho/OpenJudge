#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int s,n,i,j,k,a[20];
	char up[10]={'-',' ','-','-',' ','-','-','-','-','-'},mid[10]={' ',' ','-','-','-','-','-',' ','-','-'},down[10]={'-',' ','-','-',' ','-','-',' ','-','-'};
	char leftup[10]={'|',' ',' ',' ','|','|','|',' ','|','|'},leftdown[10]={'|',' ','|',' ',' ',' ','|',' ','|',' '};
	char rightup[10]={'|','|','|','|','|',' ',' ','|','|','|'},rightdown[10]={'|','|',' ','|','|','|','|','|','|','|'};
	while(1==1)
	{
		cin>>s>>n;
		if(s==0) break;
		for(i=1;i<=10;i++)
			a[i]=0;
		i=0;
		while(n>0)
		{
			i++;
			a[i]=n%10;
			n/=10;
		}
		n=i>1?i:1;
		for(i=n;i>=1;i--)
		{
			cout<<' ';
			for(j=1;j<=s;j++)
				cout<<up[a[i]];
			cout<<' ';
			if(i>1)cout<<' ';
		}
		cout<<endl;
		for(k=1;k<=s;k++)
		{
			for(i=n;i>=1;i--)
			{
			    cout<<leftup[a[i]];
			    for(j=1;j<=s;j++)
				    cout<<' ';
			    cout<<rightup[a[i]];
			    if(i>1)cout<<' ';
			}
			cout<<endl;
		}
        for(i=n;i>=1;i--)
		{
			cout<<' ';
			for(j=1;j<=s;j++)
				cout<<mid[a[i]];
			cout<<' ';
			if(i>1)cout<<' ';
		}
		cout<<endl;
        for(k=1;k<=s;k++)
		{
			for(i=n;i>=1;i--)
			{
			    cout<<leftdown[a[i]];
			    for(j=1;j<=s;j++)
				    cout<<' ';
			    cout<<rightdown[a[i]];
			    if(i>1)cout<<' ';
			}
			cout<<endl;
		}
        for(i=n;i>=1;i--)
		{
			cout<<' ';
			for(j=1;j<=s;j++)
				cout<<down[a[i]];
			cout<<' ';
			if(i>1)cout<<' ';
		}
		cout<<endl<<endl;
	}
	return 0;
}