#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,i,j,a[300]={0},p=0;
	char ch;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin.get();
		for(j=0;j<300;j++)
			a[j]=0;
		p=0;
		while(cin.get(ch)&&ch!=10)
		{
			a[ch]++;
			if(a[ch]>a[p]||(a[ch]==a[p]&&ch<p))p=ch;
		}
		cout<<char(p)<<' '<<a[p]<<endl;
	}
	return 0;
}