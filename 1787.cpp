#include <stdio.h>

const int dis[]={1,5,10,25};
int mem[10004][5];
int ans[5];
int cur[5];
int own[5];
int maxpay=0;
int price;

inline int max(const int x,const int y)
{
	if(x>y)return x;
	return y;
}

void f(const int x,const int y)
{
	if(x<0||y>4||(x!=0&&y==4))return;
	if(x==0)
	{
		if(cur[0]+cur[1]+cur[2]+cur[3]>maxpay)
		{
			maxpay=cur[0]+cur[1]+cur[2]+cur[3];
			ans[0]=cur[0];
			ans[1]=cur[1];
			ans[2]=cur[2];
			ans[3]=cur[3];
		}
		return;
	}
	int i;
	int tmp=0;
	for(i=0;i<=y;i++)
		tmp+=cur[i];
	if(mem[x][y]!=-1&&mem[x][y]>tmp)return;
	if(cur[y]<own[y])
	{
		if(y==0&&x%5==0&&cur[y]+5<=own[y])
		{
			cur[y]+=5;
			f(x-5,y);
			cur[y]-=5;
		}
		else
		{
			cur[y]++;
			f(x-dis[y],y);
			cur[y]--;
		}
	}
	if((y==0&&own[0]-cur[0]<=100)||(y==1&&own[1]-cur[1]<=20)||(y==2&&own[2]-cur[2]<=5)||y>=3)f(x,y+1);
	mem[x][y]=tmp;
}

int main()
{
	int i,j;
	while(1)
	{
		scanf("%d",&price);
		for(i=0;i<4;i++)
		{
			scanf("%d",own+i);
			ans[i]=cur[i]=0;
		}
		if(price==0&&own[0]==0&&own[1]==0&&own[2]==0&&own[3]==0)return 0;
		for(i=0;i<=price;i++)
			for(j=0;j<4;j++)
				mem[i][j]=-1;
		maxpay=0;
		f(price,0);
		if(maxpay==0)printf("Charlie cannot buy coffee.\n");
		else printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",ans[0],ans[1],ans[2],ans[3]);
	}
}
