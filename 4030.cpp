#include<iostream>
#include<cstring>
#include<string>
using namespace std;

inline bool chareql(const char c1,const char c2)
{
	if(c1==c2||c1+'A'-'a'==c2||c1==c2+'A'-'a')return 1;
	return 0;
}

int main()
{
	bool t,t2;
	int i,j,k,l,m,n;
	char str1[30],temp[30],ch;
	cin>>str1;
	cin.getline(temp,30,'\n');
	l=strlen(str1);
	k=m=n=t=0;
	t2=1;
	while(cin.get(ch))
	{
		if(ch==32)
		{
			t2=1;
			if(k==l)
			{
				if(!t)n-=l;
				t=1;
				m++;
			}
			else if(!t)n++;
			k=0;
		}
		else
		{
			if(!t)n++;
			if(t2)
			{
				if(k<l&&chareql(ch,str1[k]))
				{
					k++;
				}
				else
				{
					k=t2=0;
				}
			}
		}
	}
	if(m==0)cout<<"-1";
	else cout<<m<<" "<<n;
	return 0;
}