#include<iostream>
#include<cstring>
#include<string>
using namespace std;
struct data
{
	int x,y,z;
}
findlist[3][27000],end,temp[7];
int mem[40][40][40]={0};
int l,r,c,time1;
void f(int w,int s1)
{
	int i,j,x1,y1,z1,t=0,s2=0;
	for(i=1;i<=s1;i++)
	{
		for(j=1;j<=6;j++)
			temp[j]=findlist[(w+1)%2][i];
		temp[1].x++;
		temp[2].x--;
		temp[3].y++;
		temp[4].y--;
		temp[5].z++;
		temp[6].z--;
		for(j=1;j<=6;j++)
		{
			if(temp[j].x>0&&temp[j].y>0&&temp[j].z>0&&temp[j].x<=r&&temp[j].y<=c&&temp[j].z<=l)
			{
				x1=temp[j].x;
				y1=temp[j].y;
				z1=temp[j].z;
				if(mem[x1][y1][z1]==0)
				{
	//				cout<<x1<<' '<<y1<<' '<<z1<<' '<<w<<endl;
					mem[x1][y1][z1]=w;
					if(x1==end.x&&y1==end.y&&z1==end.z)
					{
						time1=w-1;
						return;
					}
					t=1;
					s2++;
					findlist[w%2][s2].x=x1;
					findlist[w%2][s2].y=y1;
					findlist[w%2][s2].z=z1;
				}
			}
		}
	}
	if(t==1)
	{
		f(w+1,s2);
	}
}
int main()
{
	int i,j,k;
	char ch;
	while(cin>>l>>r>>c)
	{
		if(l==0&&r==0&&c==0)return 0;
		cin.get();
		time1=0;
		for(i=l;i>=1;i--)
		{
			for(j=1;j<=r;j++)
			{
				for(k=1;k<=c;k++)
				{
					cin.get(ch);
					if(ch=='#')
					{
						mem[j][k][i]=-1;
					}
					else if(ch=='.')
					{
						mem[j][k][i]=0;
					}
					else if(ch=='S')
					{
						mem[j][k][i]=1;
						findlist[1][1].x=j;
						findlist[1][1].y=k;
						findlist[1][1].z=i;
					}
					else if(ch=='E')
					{
						mem[j][k][i]=0;
						end.x=j;
						end.y=k;
						end.z=i;
					}
				}
				cin.get();
			}
			cin.get();
		}
		f(2,1);
		if(time1>0)cout<<"Escaped in "<<time1<<" minute(s).\n";
		else cout<<"Trapped!\n";
	}
}