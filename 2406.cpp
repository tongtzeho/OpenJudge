#include<iostream>
#include<string>
#define MAX_LENGTH 1000003
using namespace std;
string p;
int next[MAX_LENGTH];
void calcnext()
{
	int j=0,k=-1,m=p.length();
	next[j]=k;
	while(j<m)
	{
		while(k>=0&&p[j]!=p[k])
			k=next[k];
		j++;
		k++;
		next[j]=k;
	}
}
int main()
{
	int i,l;
	while(cin>>p)
	{
		if(p==".")return 0;
		l=p.length();
		p+='*';
		calcnext();
		if(l!=next[l]&&l%(l-next[l])==0)cout<<l/(l-next[l])<<endl;
		else cout<<"1\n";
	}
}
