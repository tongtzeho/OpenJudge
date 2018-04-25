#include <stdio.h>
#include <string>

using namespace std;

string str[8][800];
int m3[9]={1};

void form(const int x)
{
	string blank;
	int i;
	for(i=1;i<=m3[x-2];i++)
		blank+=" ";
	for(i=1;i<=m3[x-2];i++)
		str[x][i]=str[x-1][i]+blank+str[x-1][i];
	for(i=m3[x-2]+1;i<=2*m3[x-2];i++)
		str[x][i]=blank+str[x-1][i-m3[x-2]]+blank;
	for(i=2*m3[x-2]+1;i<=3*m3[x-2];i++)
		str[x][i]=str[x][i-2*m3[x-2]];
}

int main()
{
	int i,n;
	for(i=1;i<=8;i++)
		m3[i]=m3[i-1]*3;
	str[1][1]="X";
	for(i=2;i<=7;i++)
		form(i);
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)return 0;
		for(i=1;i<=m3[n-1];i++)
			printf("%s\n",str[n][i].c_str());
		printf("-\n");
	}
}