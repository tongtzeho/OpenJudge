#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	int n,i,j,t,l[100]={0},a[100];
	char str[100];
	char ch[100][100],c;
	while(cin>>n)
	{
		cin.get();
		for(i=1;i<=n;i++)
		{
			l[i]=0;
			j=0;
			while(cin.get(c)&&c!='\n')
			{
				str[j]=c;
				j++;
			}
			if(str[0]=='s'&&str[1]=='t'&&str[2]=='o'&&str[3]=='p')
			{
				break;
			}
			l[i]=j;
			for(j=0;j<l[i];j++)
				ch[i][j]=str[j];
		}
		n=--i;
		for(i=1;i<=n;i++)
			a[i]=i;
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				if(l[a[i]]>l[a[j]])
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
		for(i=1;i<=n;i++)
		{
			for(j=0;j<l[a[i]];j++)
			    cout<<ch[a[i]][j];
			cout<<endl;
		}
	}
	return 0;
}