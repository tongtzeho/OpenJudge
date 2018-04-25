#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	int n,i,j,l1,l2;
	bool t=0;
	string s1,s2,s3;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		t=0;
		l1=s1.length();
		l2=s2.length();
		if(l1<l2)
		{
			s3=s1;
			s1=s2;
			s2=s3;
			l1^=l2;
			l2^=l1;
			l1^=l2;
		}
		s1=s1.substr(1,l1-1)+s1.substr(0,1);
		s3=s1;
		do
		{
			for(j=0;j<=l1-l2;j++)
				if(s2==s1.substr(j,l2))
				{
					t=1;
					break;
				}
			if(t)break;
			s1=s1.substr(1,l1-1)+s1.substr(0,1);
		}while(s1!=s3);
		if(t)cout<<"true\n";
		else cout<<"false\n";
	}
	return 0;
}