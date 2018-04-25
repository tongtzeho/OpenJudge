#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int num[10];
const int jc[]={1,1,2,6,24,120,720,5040,40320,362880};
int f(int a,int t)
{
	a--;
	int i,j,count[10]={0},temp;
	if(t!=0)
	{
		for(i=1;i<=9;i++)
		{
			num[i]=a/jc[9-i]+1;
			a%=jc[9-i];
			temp=0;
			for(j=1;j<=num[i];j++)
				if(count[j]==1)num[i]++;
			count[num[i]]++;
		}
	}
	for(i=1;i<=9;i++)
		if(num[i]==9)
		{
			j=i;
			break;
		}
	if(t==1)
	{
		if(j<=3)return 0;
		else swap(num[j],num[j-3]);
	}
	else if(t==3)
	{
		if(j%3==0)return 0;
		else swap(num[j],num[j+1]);
	}
	else if(t==2)
	{
		if(j>=7)return 0;
		else swap(num[j],num[j+3]);
	}
	else if(t==4)
	{
		if(j%3==1)return 0;
		else swap(num[j],num[j-1]);
	}
	a=0;
	for(i=1;i<=9;i++)
	{
		temp=num[i];
		for(j=1;j<i;j++)
			temp-=num[i]>num[j];
		a+=(temp-1)*jc[9-i];
	}
	return a+1;
}
int main()
{
	int i,j,st,k;
	vector<string> s1,s2;
	vector<int> v1,v2;
	bool bj[400000]={0};
	char ch;
	const string direction[5]={"","u","d","r","l"};
	for(i=1;i<=9;i++)
	{
		cin>>ch;
		if(ch=='x')num[i]=9;
		else num[i]=ch-'0';
	}
	st=f(0,0);
	bj[st]=1;
	v1.push_back(st);
	s1.push_back("");
	while(!v1.empty())
	{
		v2.clear();
		s2.clear();
		for(i=0;i<v1.size();i++)
		{
			st=v1[i];
			for(j=1;j<=4;j++)
			{
				k=f(st,j);
				if(k!=0&&!bj[k])
				{
					v2.push_back(k);
					s2.push_back(s1[i]+direction[j]);
					bj[k]=1;
				}
				if(k==1)
				{
					cout<<s2.back();
					return 0;
				}
			}
		}
		v1.swap(v2);
		s1.swap(s2);
	}
	cout<<"unsolvable";
	return 0;
}