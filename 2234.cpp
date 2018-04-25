#include<iostream>
using namespace std;
int main()
{
	int *a,n,i,t;
	while(cin>>n)
	{
		t=0;
		a=new int[n+1];
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			t^=a[i];
		}
		if(t==0)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
