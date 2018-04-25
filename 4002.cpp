#include<iostream>
using namespace std;
int main()
{
	int a[201]={0},b[201]={0},n,m,i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	}
	for(i=1;i<=n;i++)
	{
		if(b[a[i]]==1)cout<<"BeiJu\n";
		else cout<<b[a[i]]-1<<endl;
	}
	return 0;
}