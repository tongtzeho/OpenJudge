#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	string st[200];
	int n,i,j,k,b[20][40][200]={0},m,d;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>st[i]>>m>>d;
		b[m][d][0]++;
		b[m][d][b[m][d][0]]=i;
	}
	for(i=1;i<=12;i++)
		for(j=1;j<=31;j++)
			if(b[i][j][0]>1)
			{
			    cout<<i<<' '<<j;
			    for(k=1;k<=b[i][j][0];k++)
				    cout<<' '<<st[b[i][j][k]];
			    cout<<endl;
			}
	return 0;
}