#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	string st1[200],st;
	int n=0,i,j;
	while(cin>>st1[n]&&n<4)
		n++;
	for(i=0;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(st1[i]>st1[j])
			{
				st=st1[i];
				st1[i]=st1[j];
				st1[j]=st;
			}
	for(i=0;i<=n;i++)
		cout<<st1[i]<<endl;
	return 0;
}
