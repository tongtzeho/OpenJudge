#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char st1[120],st2[120];
	int i,j,s1,s2,t;
	while(cin.getline(st1,100,'\n'))
	{
		cin.getline(st2,100,'\n');
		s1=0;
		t=0;
		for(i=0;i<strlen(st1);i++)
		{
			if(((st1[i]>=65&&st1[i]<=90)||(st1[i]>=97&&st1[i]<=122))&&(t==0))
			{
				t=1;
				j=i;
			}
			if(t==1)
				if(st1[i]==st1[j])s1++;
		}
		s2=0;
		for(i=0;i<strlen(st2);i++)
			if(st2[i]==st1[j])s2++;
		cout<<(s1<=s2)<<endl;
	}
	return 0;
}
