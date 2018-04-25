#include<iostream>
using namespace std;
int step[100][100]={0},mem[100][100]={0},a[100][100]={0},r,c;
void search(int st,int m[ ],int n[ ])
{
	int i,j,k,t,x[2000]={0},y[2000]={0};
	t=k=1;
	while(m[k]!=0&&n[k]!=0)
	{
		i=m[k];
		j=n[k];
		if(a[i-1][j]==1&&mem[i-1][j]==0)
		{
			mem[i-1][j]=1;
			step[i-1][j]=st;
			x[t]=i-1;
			y[t]=j;
			t++;
		}
		if(a[i+1][j]==1&&mem[i+1][j]==0)
		{
			mem[i+1][j]=1;
			step[i+1][j]=st;
			x[t]=i+1;
			y[t]=j;
			t++;
		}
		if(a[i][j-1]==1&&mem[i][j-1]==0)
		{
			mem[i][j-1]=1;
			step[i][j-1]=st;
			x[t]=i;
			y[t]=j-1;
			t++;
		}
		if(a[i][j+1]==1&&mem[i][j+1]==0)
		{
			mem[i][j+1]=1;
			step[i][j+1]=st;
			x[t]=i;
			y[t]=j+1;
			t++;
		}
		k++;
	}
	if(mem[r][c]==1)return;
	search(st+1,x,y);
}
int main()
{
	int i,j,k,m[2000]={0,1},n[2000]={0,1};
	char ch;
	cin>>r>>c;
	cin.get();
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			cin.get(ch);
			if(ch=='.')a[i][j]=1;
			if(ch=='#')step[i][j]=999999;
		}
		cin.get();
	}
	mem[1][1]=step[1][1]=1;
	search(2,m,n);
	//for(i=1;i<=r;i++)
	//{
	//	for(j=1;j<=c;j++)
	//		cout<<step[i][j]<<' ';
	//	cout<<endl;
	//}
	cout<<step[r][c];
	return 0;
}