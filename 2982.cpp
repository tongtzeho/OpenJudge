#include<iostream>
#include<string>
#include<cstring>
using namespace std;

void input(char sudoku[][10]);
void output(char sudoku[][10]);
int solve(char sudoku[][10]);
int searchans(char sudoku[][10],int gong,int emptynum[]);

void input(char sudoku[][10])
{
	string str;
	int i,j;
	for(i=0;i<9;i++)
	{
		cin>>str;
		for(j=0;j<9;j++)
			sudoku[i+1][j+1]=str[j]-'0';
	}
}

void output(char sudoku[][10])
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
			cout<<int(sudoku[i][j]);
		cout<<endl;
	}
}

int solve(char sudoku[][10])
{
	int i,j,k,firstsearch=1,emptynum[10]={0};
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=3;j++)
			for(k=1;k<=3;k++)
				emptynum[i]+=(sudoku[3*((i-1)/3)+j][3*((i-1)%3)+k]==0);
		if(emptynum[i]<emptynum[firstsearch]&&emptynum[i]!=0)firstsearch=i;
	}
	return searchans(sudoku,firstsearch,emptynum);
}

int searchans(char sudoku[][10],int gong,int emptynum[])
{
	int i,j,fi,fj,tmp,nextsearch=0;
	bool putnum[10]={0};
	static bool solved=0;
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
		{
			if(sudoku[3*((gong-1)/3)+i][3*((gong-1)%3)+j]==0)
			{
				fi=3*((gong-1)/3)+i;
				fj=3*((gong-1)%3)+j;
			}
			else putnum[sudoku[3*((gong-1)/3)+i][3*((gong-1)%3)+j]]=1;
		}
	for(i=1;i<=9;i++)
	{
		if(!putnum[i])
		{
			bool canput=1;
			for(j=1;j<=9;j++)
				if(sudoku[fi][j]==i||sudoku[j][fj]==i)
				{
					canput=0;
					break;
				}
			if(canput)
			{
				sudoku[fi][fj]=i;
				emptynum[gong]--;
				for(j=1;j<=9;j++)
					if(emptynum[j]!=0)
					{
						nextsearch=j;
						break;
					}
				if(nextsearch==0)
				{
					solved=1;
					return 1;
				}
				for(j=nextsearch+1;j<=9;j++)
					if(emptynum[j]<emptynum[nextsearch]&&emptynum[j]!=0)nextsearch=j;
				if(searchans(sudoku,nextsearch,emptynum)==1)return 1;
				sudoku[fi][fj]=0;
				emptynum[gong]++;
			}
		}
	}
	return 0;
}

int main()
{
	int i,testdata;
	char sudoku[10][10];
	cin>>testdata;
	for(i=0;i<testdata;i++)
	{
		input(sudoku);
		solve(sudoku);
		output(sudoku);
	}
	return 0;
}