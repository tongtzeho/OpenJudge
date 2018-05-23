#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	char c1[200],c2[200],ch;
	int n,i,j,k1,k2,s,t;
	cin>>n;
	cin.get();
	for(i=1;i<=n;i++)
	{
		t=1;
		for(j=0;j<200;j++)
			c1[j]=c2[j]='\0';
		k1=0;
		k2=0;
		while(cin.get(ch)&&ch!='\n')
		{
			if(ch!=32)c1[k1]=ch;
			if(ch>=97&&ch<=122)c1[k1]=ch-32;
			if(ch!=32)k1++;
		}
		while(cin.get(ch)&&ch!='\n')
		{
			if(ch!=32)c2[k2]=ch;
			if(ch>=97&&ch<=122)c2[k2]=ch-32;
			if(ch!=32)k2++;
		}
		if(k1!=k2)t=0;
		else for(j=0;j<k1;j++)
			if(c1[j]!=c2[j])t=0;
		cin.get();
		if(t==1)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}