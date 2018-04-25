#include<iostream>
using namespace std;
int main()
{
	int n,i,a[9];
	char ch;
	while(cin>>n)
	{
		if(n==-1)return 0;
		for(i=1;i<=8;i++)
		{
			a[i]=n%2;
			n/=2;
		}
		for(i=8;i>=1;i--)
			cout<<a[i];
		do
		{
			cin.get(ch);
		}while(ch!='.'&&ch!=10);
		if(ch==10)cout<<endl;
	}
}