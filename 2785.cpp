#include<iostream>
using namespace std;
struct data
{
	char c;
	int x,y,mp,at,hp,walk;
}
man[1001];
inline int minnum(int x,int y)
{
	if(x<y)return x;
	return y;
}
inline int maxnum(int x,int y)
{
	if(x>y)return x;
	return y;
}
inline int calc(int a)
{
	if(man[a].c=='S')return int((0.5*man[a].mp+0.5*man[a].at)*(man[a].hp+10.0)/double(100.0));
	if(man[a].c=='W')return int((0.8*man[a].mp+0.2*man[a].at)*(man[a].hp+10.0)/double(100.0));
	if(man[a].c=='E')return int((0.2*man[a].mp+0.8*man[a].at)*(man[a].hp+10.0)/double(100.0));
}
int main()
{
	int n,step,i,j,k,l,atk1,atk2,mansum,pos[13][13][1001]={0},possum[13][13]={0},c1,c2,ssum,slife,wsum,wlife,esum,elife;
	char temp;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>step;
		for(j=1;j<=12;j++)
			for(k=1;k<=12;k++)
				possum[j][k]=0;
		mansum=ssum=slife=wsum=wlife=esum=elife=0;
		while(cin>>temp&&temp!='0')
		{
			mansum++;
			man[mansum].c=temp;
			cin>>man[mansum].x>>man[mansum].y>>man[mansum].mp>>man[mansum].at>>man[mansum].hp;
			possum[man[mansum].x][man[mansum].y]++;
			pos[man[mansum].x][man[mansum].y][possum[man[mansum].x][man[mansum].y]]=mansum;
			man[mansum].walk=1;
		}
		for(j=1;j<=step;j++)
		{
			for(k=1;k<=12;k++)
				for(l=1;l<=12;l++)
				{
					if(possum[k][l]==2)
					{
						c1=man[pos[k][l][1]].c;
						c2=man[pos[k][l][2]].c;
						if(c1!=c2)
						{
							atk1=calc(pos[k][l][1]);
							atk2=calc(pos[k][l][2]);
							man[pos[k][l][1]].hp-=atk2;
							man[pos[k][l][2]].hp-=atk1;
						}
					}
					possum[k][l]=0;
				}
			for(k=1;k<=mansum&&j!=step;k++)
			{
				if(man[k].hp>0)
				{
					if(man[k].c=='S')
					{
						if(man[k].x==12)man[k].walk=-1;
						if(man[k].x==1)man[k].walk=1;
						man[k].x+=man[k].walk;
						possum[man[k].x][man[k].y]++;
						pos[man[k].x][man[k].y][possum[man[k].x][man[k].y]]=k;
					}
					if(man[k].c=='W')
					{
						if(man[k].y==12)man[k].walk=-1;
						if(man[k].y==1)man[k].walk=1;
						man[k].y+=man[k].walk;
						possum[man[k].x][man[k].y]++;
						pos[man[k].x][man[k].y][possum[man[k].x][man[k].y]]=k;
					}
					if(man[k].c=='E')
					{
						if(maxnum(man[k].x,man[k].y)==12)man[k].walk=-1;
						if(minnum(man[k].x,man[k].y)==1)man[k].walk=1;
						if(maxnum(man[k].x,man[k].y)==12&&minnum(man[k].x,man[k].y)==1)man[k].walk=0;
						man[k].x+=man[k].walk;
						man[k].y+=man[k].walk;
						possum[man[k].x][man[k].y]++;
						pos[man[k].x][man[k].y][possum[man[k].x][man[k].y]]=k;
					}
				}
			}
		}
		for(j=1;j<=mansum;j++)
		{
			if(man[j].c=='S'&&man[j].hp>0)
			{
				ssum++;
				slife+=man[j].hp;
			}
			if(man[j].c=='W'&&man[j].hp>0)
			{
				wsum++;
				wlife+=man[j].hp;
			}
			if(man[j].c=='E'&&man[j].hp>0)
			{
				esum++;
				elife+=man[j].hp;
			}
		}
		cout<<ssum<<' '<<slife<<endl<<wsum<<' '<<wlife<<endl<<esum<<' '<<elife<<endl<<"***\n";
	}
	return 0;
}
