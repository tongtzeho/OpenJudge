#include<iostream>
#include<vector>
using namespace std;
int f(int n,const int t)
{
	bool a[16]={0};
	int i,j;
	for(j=0;j<16;j++)
	{
		a[j]=n%2;
		n/=2;
	}
	a[t]=!a[t];
	if(t%4!=0)a[t-1]=!a[t-1];
	if(t%4!=3)a[t+1]=!a[t+1];
	if(t>=4)a[t-4]=!a[t-4];
	if(t<12)a[t+4]=!a[t+4];
	i=1;
	n=0;
	for(j=0;j<16;j++)
	{
		n+=a[j]*i;
		i*=2;
	}
	return n;
}
int main()
{
	bool a[16],bj[65536]={0};
	int i,j,k=0,m=0,st,temp;
	char ch[6];
	for(i=0;i<4;i++)
	{
		cin>>ch;
		for(j=0;j<4;j++)
			a[i*4+j]=ch[j]=='b';
	}
	st=0;
	i=1;
	for(j=0;j<16;j++)
	{
		st+=a[j]*i;
		i*=2;
	}
	if(st==0||st==65535)
	{
		cout<<0;
		return 0;
	}
	vector<int> v1,v2;
	v1.push_back(st);
	bj[st]=1;
	while(!v1.empty())
	{
		k++;
		for(j=0;j<v1.size();j++)
		    for(i=0;i<16;i++)
			{
			    temp=f(v1[j],i);
			    if(!bj[temp])
				{
				    if(temp==0||temp==65535)
					{
					    cout<<k;
					    return 0;
					} 
				    bj[temp]=1;
				    v2.push_back(temp);
				}
			}
		v1.clear();
		v2.swap(v1);
	}
	cout<<"Impossible";
	return 0;
}