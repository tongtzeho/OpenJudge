#include<iostream>
using namespace std;
bool mem[8][150000],divi;
int v[8]={0},sum,s[8]={0};
void f(const int x,const int y)
{
	if((x==1&&y<=v[1])||y==0||divi||y==s[x])
	{
		divi=1;
		return;
	}
	else if(x==1||y<0||mem[x][y]||y>s[x])return;
	int i,j=y;
	for(i=0;i<=v[x]&&j>=0;i++)
	{
		j=y-i*x;
		if(j>=0)f(x-1,j);
		if(divi)return;
	}
	mem[x][y]=1;
}
int main()
{
	int i,j=0,k;
	while(cin>>v[1]>>v[2]>>v[3]>>v[4]>>v[5]>>v[6])
	{
		divi=0;
		sum=0;
		for(i=1;i<=6;i++)
		{
			sum+=i*v[i];
			s[i]=s[i-1]+i*v[i];
		}
		if(sum==0)return 0;
		j++;
		cout<<"Collection #"<<j<<":\n";
		if(sum%2==1)
		{
			cout<<"Can't be divided.\n\n";
			continue;
		}
		for(i=1;i<=6;i++)
			for(k=0;k<=sum/2;k++)
				mem[i][k]=0;
		f(6,sum/2);
		if(divi)cout<<"Can be divided.\n\n";
		else cout<<"Can't be divided.\n\n";
	}
}