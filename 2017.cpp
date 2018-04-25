#include<iostream>
using namespace std;
int main()
{
	int n,i,a,b,s,l;
	while(cin>>n)
	{
		if(n==-1)return 0;
		s=l=0;
	    for(i=1;i<=n;i++)
		{
		    cin>>a>>b;
		    l+=a*(b-s);
		    s=b;
		}
		cout<<l<<" miles"<<endl;
	}
}