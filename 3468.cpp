#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;
int main()
{
	int *a;
	int n,i,j,s1=0,s2=0,m;
	double ans;
	cout<<setiosflags(ios::fixed)<<setprecision(1);
	while(cin>>n)
	{
		a=new int[n+1];
		s1=0;
		m=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s1+=a[i];
			if(a[i]>m)m=a[i];
		}
		s2=s1-m;
		if(s1>=2*s2)cout<<double(s2)<<endl;
		else cout<<double(s1)/2<<endl;
		delete a;
	}
	return 0;
}