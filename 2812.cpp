#include<iostream>
#include<stdlib.h>
using namespace std;
struct pointorder
{
	short x,y;
}*p;
short **b;
inline short maxnum(short,short);
inline short minnum(short,short);
short calc(short,short,short,short,short,short);
inline bool notin(short,short,short,short);
inline short maxnum(short x,short y)
{
	if(x>y)return x;
	return y;
}
inline short minnum(short x,short y)
{
	if(x<y)return x;
	return y;
}
short calc(short x1,short y1,short x2,short y2,short r,short c)
{
	short dx=x2-x1,dy=y2-y1;
	if(dx==0)return (c-y1)/dy+1;
	if(dy==0)return (r-x1)/dx+1;
	if(dy>0)return minnum((r-x1)/dx+1,(c-y1)/dy+1);
	short temp;
	dy=-dy;
	if(y1%dy==0)temp=y1/dy;
	else temp=y1/dy+1;
	return minnum((r-x1)/dx+1,temp);
}
inline bool notin(short x,short y,short r,short c)
{
	if(x<=0||y<=0||x>r||y>c)return 1;
	return 0;
}
int cmp(const void *p1,const void *p2)
{
	struct pointorder *p3=(pointorder*)p1;
	struct pointorder *p4=(pointorder*)p2;
	if(p3->x!=p4->x)return p3->x-p4->x;
	return p3->y-p4->y;
}
int main()
{
	int i,j;
	short r,c,x,y,dx,dy,maxtotal,total,n,best=0;
	bool t;
	cin>>r>>c>>n;
	b=new short*[r+1];
	for(i=0;i<=r;i++)
	{
		b[i]=new short[c+1];
		for(j=0;j<=c;j++)
			b[i][j]=-1;
	}
	p=new pointorder[n+1];
	for(i=1;i<=n;i++)
	{
		cin>>x>>y;
		p[i].x=x;
		p[i].y=y;
		b[x][y]=0;
	}
	maxtotal=maxnum(r,c);
	if(maxtotal<3)
	{
		cout<<0;
		return 0;
	}
	p[0].x=p[0].y=0;
	qsort(p,n+1,sizeof(p[0]),cmp);
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		{
			if(2*p[i].x<=p[j].x||2*p[i].y<=p[j].y||p[j].y+c<=2*p[i].y)
			{
				total=calc(p[i].x,p[i].y,p[j].x,p[j].y,r,c);
				x=p[j].x;
				y=p[j].y;
				if(b[x][y]<total)
				{
					dx=p[j].x-p[i].x;
					dy=p[j].y-p[i].y;
				    do
					{
					    x+=dx;
					    y+=dy;
					    if(notin(x,y,r,c))
						{
						    t=1;
						    break;
						}
					    else if(b[x][y]==-1||b[x][y]>=total)
						{
						    t=0;
						    break;
						}
					}while(1);
				    if(t)
					{
					    best=maxnum(best,total);
					    if(best==maxtotal)
						{
						    cout<<best;
						    return 0;
						}
					    x-=dx;
					    y-=dy;
					    do
						{
						    b[x][y]=best;
						    x-=dx;
						    y-=dy;
						}while(!notin(x,y,r,c));
					}
				}
			}
		}
	if(best<3)cout<<0;
	else cout<<best;
	return 0;
}