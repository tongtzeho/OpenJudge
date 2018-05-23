#include<iostream>
using namespace std;
int a[30][30],mem[30][30],sum=1;
void change(int x,int y)
{
	if (a[x+1][y]==1&&mem[x+1][y]==-1)
	{
		sum++;
		mem[x+1][y]=1;
		change(x+1,y);
	}
	if (a[x-1][y]==1&&mem[x-1][y]==-1)
	{
		sum++;
		mem[x-1][y]=1;
		change(x-1,y);
	}
	if (a[x][y-1]==1&&mem[x][y-1]==-1)
	{
		sum++;
		mem[x][y-1]=1;
		change(x,y-1);
	}
	if (a[x][y+1]==1&&mem[x][y+1]==-1)
	{
		sum++;
		mem[x][y+1]=1;
		change(x,y+1);
	}
	return;
}
int main()
{
	int w,h,i,j,x1,y1;
	char ch;
	while(1==1)
	{
		sum=1;
		cin>>w>>h;
		for(i=0;i<=h+1;i++)
			for(j=0;j<=w+1;j++)
			{
				a[i][j]=0;
				mem[i][j]=i==0||i==h+1||j==0||j==w+1?0:-1;
			}
		if(w==0)return 0;
		i=0;
		while(i<=h)
		{
			j=1;
			while(1==1)
			{
				cin.get(ch);
				if(ch=='\n')break;
				if(ch=='.')a[i][j]=1;
				if(ch=='#')mem[i][j]=a[i][j]=0;
				if(ch=='@')
				{
					a[i][j]=3;
					mem[i][j]=1;
					x1=i;
					y1=j;
				}
				j++;
			}
			i++;
		}
		change(x1,y1);
		cout<<sum<<endl;
	}
}