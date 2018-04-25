#include<iostream>
using namespace std;
int main()
{
	int n,i,j,m;
	double a1,a2,a3,c;
	while(cin>>n)
	{
		if(n==-1)return 0;
		a1=a2=a3=m=0;
		for(i=1;i<=n;i++)
		{
			cin>>j>>c;
			m+=j;
			a1+=c*j;
		}
		if(a1>100)a2=a1;
		else a2=a1+20;
		if(m>3)a3=a1*0.95+20;
		else a3=a1+20;
		if(a2<a3)cout<<a2<<endl;
		else cout<<a3<<endl;
	}
}
