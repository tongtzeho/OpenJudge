#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	int n,i,j,t,weight[200]={0};
	string color[200],st;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>weight[i]>>color[i];
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(weight[i]<weight[j])
			{
				t=weight[i];
				weight[i]=weight[j];
				weight[j]=t;
				st=color[i];
				color[i]=color[j];
				color[j]=st;
			}
	for(i=1;i<=n;i++)
		cout<<color[i]<<endl;
	return 0;
}