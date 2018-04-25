#include<stdio.h>
struct data
{
	int x1,y1,x2,y2;
}
*coor;
int main()
{
	int n,i,x,y,t=0;
	scanf("%d",&n);
	coor=new data[n+1];
	for(i=1;i<=n;i++)
		scanf("%d %d %d %d",&coor[i].x1,&coor[i].y1,&coor[i].x2,&coor[i].y2);
	scanf("%d %d",&x,&y);
	for(i=n;i>=1;i--)
		if(coor[i].x1<=x&&coor[i].y1<=y&&coor[i].x1+coor[i].x2>x&&coor[i].y1+coor[i].y2>y)
		{
			t=1;
			break;
		}
	if(t==1)printf("%d",i);
	else printf("-1");
	return 0;
}