#include<iostream>
using namespace std;
int f(int a,int b,int c)
{
	if(a%b==0)return a/b;
	if(a%b+c<=b) return a/b;
	return a/b+1;
}
int main()
{
	int n,i,j,most[401],s,k;
	double t,m=0;
	cin>>n;
	for(i=2;2*i+(i-1)*i/2<=n;i++)
	{
		t=1;
		s=n-(i-1)*i/2;
		for(j=1;j<=i;j++)
			t*=f(s,i,j)+j-1;
		if(t>m)
		{
			for(j=1;j<=i;j++)
				most[j]=f(s,i,j)+j-1;
			m=t;
			k=i;
		}
	}
	for(i=1;i<k;i++)
		cout<<most[i]<<' ';
	cout<<most[k];
	return 0;
}
