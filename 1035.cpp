#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> v;
vector<int> v2;
bool cmp(string dic,string st)
{
	int i,j,l1=dic.length(),l2=st.length();
	if(l1==l2)
	{
		for(i=0;i<l1;i++)
			if(dic[i]!=st[i])break;
		for(j=l1-1;j>=0;j--)
			if(dic[j]!=st[j])break;
		return i==j;
	}
	else if(l1-l2==1)
	{
		for(i=0;i<l2;i++)
			if(st[i]!=dic[i])break;
		for(j=i;j<l2;j++)
			if(st[j]!=dic[j+1])return 0;
		return 1;
	}
	else if(l2-l1==1)
	{
		for(i=0;i<l2;i++)
		{
			string st2=st.substr(0,i)+st.substr(i+1,l2-i-1);
			if(st2==dic)return 1;
		}
	}
	return 0;
}
int main()
{
	string st;
	int i,j,k;
	while(cin>>st)
	{
		if(st.length()==1&&st[0]=='#')break;
		v.push_back(st);
	}
	while(cin>>st)
	{
		if(st.length()==1&&st[0]=='#')return 0;
		v2.clear();
		bool t=0;
		for(i=0;i<v.size();i++)
		{
			if(v[i]==st)
			{
				t=1;
				cout<<st<<" is correct\n";
				break;
			}
			else if(cmp(v[i],st))v2.push_back(i);
		}
		if(!t)
		{
			cout<<st<<":";
			for(i=0;i<v2.size();i++)
				cout<<" "<<v[v2[i]];
			cout<<endl;
		}
	}
}