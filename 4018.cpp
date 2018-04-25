#include<iostream>
#include<cstring>
#include<string>
using namespace std;
bool subover;
bool substr(string st1,string st2)
{
	if(st1.length()>st2.length()||(st1.length()==st2.length()&&st1!=st2))return false;
	int i,l1=st1.length(),l2=st2.length();
	for(i=0;i<l2;i++)
		if(st1[0]==st2[i])
		{
			if(l1==1)
			{
				subover=true;
				return true;
			}
			else if(!subover)return substr(st1.substr(1,l1-1),st2.substr(i+1,l2-i-1));
			else return true;
		}
	return false;
}
int main()
{
	string st1,st2;
	while(cin>>st1>>st2)
	{
		subover=false;
		substr(st1,st2)?cout<<"Yes\n":cout<<"No\n";
	}
	return 0;
}