#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int w,h,seg[100][100]={0},a[100][100]={0},mx[2][5000],my[2][5000],x1,x2,y1,y2,segment;
void search(int se)
{
	int i,j,s,t=0;
	for(i=1;i<5000;i++)
	{
		if(mx[(se+1)%2][i]==-1&&my[(se+1)%2][i]==-1)break;
		mx[(se+1)%2][i]=my[(se+1)%2][i]=-1;
	}
	for(i=1;i<5000;i++)
	{
		if(mx[se%2][i]==-1)break;
		for(j=mx[se%2][i]-1;j>=0;j--)//left
		{
			if(a[my[se%2][i]][j]==0)break;
			if(seg[my[se%2][i]][j]==-1)
			{
				t++;
				seg[my[se%2][i]][j]=se+1;
				mx[(se+1)%2][t]=j;
				my[(se+1)%2][t]=my[se%2][i];
			}
		}
		for(j=mx[se%2][i]+1;j<=w+1;j++)//right
		{
			if(a[my[se%2][i]][j]==0)break;
			if(seg[my[se%2][i]][j]==-1)
			{
				t++;
				seg[my[se%2][i]][j]=se+1;
				mx[(se+1)%2][t]=j;
				my[(se+1)%2][t]=my[se%2][i];
			}
		}
		for(j=my[se%2][i]-1;j>=0;j--)//up
		{
			if(a[j][mx[se%2][i]]==0)break;
			if(seg[j][mx[se%2][i]]==-1)
			{
				t++;
				seg[j][mx[se%2][i]]=se+1;
				mx[(se+1)%2][t]=mx[se%2][i];
				my[(se+1)%2][t]=j;
			}
		}
		for(j=my[se%2][i]+1;j<=h+1;j++)//down
		{
			if(a[j][mx[se%2][i]]==0)break;
			if(seg[j][mx[se%2][i]]==-1)
			{
				t++;
				seg[j][mx[se%2][i]]=se+1;
				mx[(se+1)%2][t]=mx[se%2][i];
				my[(se+1)%2][t]=j;
			}
		}
	}
	if(seg[y2][x2]>0)
	{
		segment=seg[y2][x2];
		return;
	}
	if(t==0)return;
	search(se+1);
}
int main()
{
	int i,j,k,b=0,p=0;
	char ch;
	while(cin>>w>>h)
	{
		b++;
		p=0;
		if(w==0&&h==0)return 0;
		cout<<"Board #"<<b<<":\n";
		cin.get();
		for(i=0;i<=h+1;i++)
			for(j=0;j<=w+1;j++)
				a[i][j]=1;
		for(i=1;i<=h;i++)
		{
			for(j=1;j<=w;j++)
			{
				cin.get(ch);
				if(ch=='X')a[i][j]=0;
			}
			cin.get();
		}
		while(cin>>x1>>y1>>x2>>y2)
		{
			p++;
			if(x1==0&&y1==0)break;
			cout<<"Pair "<<p<<": ";
			for(i=0;i<=h+1;i++)
			    for(j=0;j<=w+1;j++)
				    seg[i][j]=-1;
			for(i=0;i<5000;i++)
				mx[0][i]=mx[1][i]=my[0][i]=my[1][i]=-1;
			segment=-1;
			a[y1][x1]=a[y2][x2]=2;
			seg[y1][x1]=0;
			my[0][1]=y1;
			mx[0][1]=x1;
			search(0);
			if(segment>0)cout<<segment<<" segments.\n";
			else cout<<"impossible.\n";
			a[y1][x1]=a[y2][x2]=0;
		}
		cout<<endl;
	}
}
