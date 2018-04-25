#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	string ch;
	int i,j,k,n,m,t;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ch;
		for(j=0;j<=3;j++)
		{
			m=0;
			t=1;
			for(k=7+8*j;k>=8*j;k--)
			{
				m+=t*int(ch[k]-48);
				t*=2;
			}
			cout<<m;
			if(j<=2)cout<<'.';
			else cout<<endl;
		}
	}
	return 0;
}