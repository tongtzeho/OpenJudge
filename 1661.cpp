#include<iostream>
using namespace std;
struct data
{
	int x1,x2,h,a,b;
};
inline int min(int x,int y)
{
	if(x<y)return x;
	return y;
}
int main()
{
	const int MAXINT=50000000;
	data *step,temp;
	int testdatasum,i,j,k,n,x,y,max;
	bool t1,t2;
	cin>>testdatasum;
	for(i=1;i<=testdatasum;i++)
	{
		cin>>n>>x>>y>>max;
		step=new data[n+1];
		for(j=1;j<=n;j++)
			cin>>step[j].x1>>step[j].x2>>step[j].h;
		for(j=1;j<=n;j++)
			for(k=j+1;k<=n;k++)
				if(step[j].h>step[k].h)
				{
					temp=step[j];
					step[j]=step[k];
					step[k]=temp;
				}
		for(j=1;j<=n;j++)
			if(step[j].h>=y)
			{
				n=j-1;
				break;
			}
		for(j=1;j<=n;j++)
		{
			t1=t2=0;
			for(k=j-1;k>=1;k--)
			{
				if(step[k].x1<=step[j].x1&&step[k].x2>=step[j].x1&&step[j].h-step[k].h<=max)
				{
					t1=1;
					step[j].a=min(step[k].a+step[j].x1-step[k].x1,step[k].b+step[k].x2-step[j].x1)+step[j].h-step[k].h;
					break;
				}
				else if(step[j].h-step[k].h>max)
				{
					t1=1;
					step[j].a=MAXINT;
					break;
				}
			}
			if(!t1)
			{
				if(step[j].h<=max)step[j].a=step[j].h;
				else step[j].a=MAXINT;
			}
			for(k=j-1;k>=1;k--)
			{
				if(step[k].x1<=step[j].x2&&step[k].x2>=step[j].x2&&step[j].h-step[k].h<=max)
				{
					t2=1;
					step[j].b=min(step[k].a+step[j].x2-step[k].x1,step[k].b+step[k].x2-step[j].x2)+step[j].h-step[k].h;
					break;
				}
				else if(step[j].h-step[k].h>max)
				{
					t2=1;
					step[j].b=MAXINT;
					break;
				}
			}
			if(!t2)
			{
				if(step[j].h<=max)step[j].b=step[j].h;
				else step[j].b=MAXINT;
			}
		}
		t1=1;
		for(j=n;j>=1;j--)
			if(step[j].x1<=x&&step[j].x2>=x)
			{
				k=min(step[j].a+x-step[j].x1,step[j].b+step[j].x2-x)+y-step[j].h;
				t1=0;
				break;
			}
		if(t1)k=y;
		cout<<k<<endl;
		delete []step;
	}
	return 0;
}