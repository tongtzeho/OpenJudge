#include<iostream>
#include<cstring>
#include<string>
using namespace std;
char st[3][2000],st3[2000];
int l[3],l3;
bool eql(int x,int y)
{
	int i;
	for(i=0;i<l[y];i++)
		if(st3[i+x]!=st[y][i])return 0;
	return 1;
}
int main()
{
	int i,j,k,t1,t2,n;
	cin>>st[1]>>st[2]>>n;
	l[1]=strlen(st[1]);
	l[2]=strlen(st[2]);
	for(i=1;i<=n;i++)
	{
		cin>>st3;
		l3=strlen(st3);
		for(j=0;j<=l3-l[1];j++)
			if(eql(j,1))
			{
				t1=j;
				break;
			}
		for(j=l3-l[2];j>=t1;j--)
			if(eql(j,2))
			{
				t2=j+l[2]-1;
				break;
			}
		for(j=t1;j<=t2;j++)
			cout<<st3[j];
		cout<<endl;
	}
	return 0;
}