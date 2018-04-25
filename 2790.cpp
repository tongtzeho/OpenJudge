#include<iostream>
using namespace std;
int a[120][120],mem[120][120],sum=1;
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
	int w,h,i,j,x1,y1,n,k,x2,y2;
	char ch;
	cin>>n;
    for(k=1;k<=n;k++)
	{
		sum=1;
		cin>>w;
		h=w;
		for(i=0;i<=h+1;i++)
			for(j=0;j<=w+1;j++)
			{
				a[i][j]=0;
				mem[i][j]=i==0||i==h+1||j==0||j==w+1?0:-1;
			}
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
				j++;
			}
			i++;
		}
		cin>>x1>>y1>>x2>>y2;
		x1++;
		y1++;
		x2++;
		y2++;
		if(a[x1][y1]==0||a[x2][y2]==0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		mem[x1][y1]=1;
		a[x1][y1]=3;
		change(x1,y1);
		if(mem[x2][y2]==1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}