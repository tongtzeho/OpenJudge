#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int m2[]={0,1,2,4,8,16,32,64,128,256,512,1024};
short mems[1025]={0},memf[2][1025][1025]={0};
bool memt[1025]={1};
int r,c,a[102]={0};

inline int cc(const int x,const int y)
{
	return (x&(m2[c+1]-1-y));
}

class LIST
{
public:
	int s,n[70];
	void create(const int num)
	{
		s=0;
		int i;
		for(i=1;i<=num;i++)
			if(((i&num)==i)&&((i|num)==num)&&memt[i])
			{
				s++;
				n[s]=i;
			}
		s++;
		n[s]=0;
	}
}list[1025];

int main()
{
	cin>>r>>c;
	int i,j,k,n1,n2,n3,p,q,temp2,s=0,max=0;
	bool t2;
	char ch;
	cin.get();
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			cin.get(ch);
			a[i]+=(ch=='P')*m2[c+1-j];
		}
		cin.get();
	}
	if(r%2==0)r++;
	for(i=1;i<=m2[c+1]-1;i++)
	{
		for(j=c;j>=1;j--)
			if(i>=m2[j])break;
		if(j>3)mems[i]=mems[i&(m2[j-2]-1)]+1;
		else mems[i]=1;
		k=i;
		j=t2=0;
		while(k>0)
		{
			if(k&1==1)
			{
				if(t2&&j<2)break;
				j=0;
				t2=1;
			}
			else 
			{
				j++;
			}
			k>>=1;
		}
		if(k>0)memt[i]=0;
		else memt[i]=1;
		list[i].create(i);
	}
	list[0].create(0);
	for(j=1;j<=list[a[1]].s;j++)
	{
		n1=cc(a[2],list[a[1]].n[j]);
		for(k=1;k<=list[n1].s;k++)
			memf[1][list[a[1]].n[j]][list[n1].n[k]]=mems[list[a[1]].n[j]]+mems[list[n1].n[k]];
	}
	for(i=3;i<r;i+=2)
	{
		s++;
		for(j=1;j<=list[a[i-2]].s;j++)
		{
			n1=cc(a[i-1],list[a[i-2]].n[j]);
			for(k=1;k<=list[n1].s;k++)
			{
				n2=cc(a[i],list[a[i-2]].n[j]);
				n2=cc(n2,list[n1].n[k]);
				for(p=1;p<=list[n2].s;p++)
				{
					n3=cc(a[i+1],list[n1].n[k]);
					n3=cc(n3,list[n2].n[p]);
					for(q=1;q<=list[n3].s;q++)
					{
						temp2=memf[s%2][list[a[i-2]].n[j]][list[n1].n[k]]+mems[list[n2].n[p]]+mems[list[n3].n[q]];
						if(temp2>memf[(s+1)%2][list[n2].n[p]][list[n3].n[q]])memf[(s+1)%2][list[n2].n[p]][list[n3].n[q]]=temp2;
					}
				}
			}
		}
	}
	s++;
	i=r;
	for(j=1;j<=list[a[r-2]].s;j++)
	{
		n1=cc(a[r-1],list[a[r-2]].n[j]);
		for(k=1;k<=list[a[r-1]].s;k++)
		{
			n2=cc(a[i],list[a[i-2]].n[j]);
			n2=cc(n2,list[n1].n[k]);
			for(p=1;p<=list[n2].s;p++)
			{
				if(memf[s%2][list[a[i-2]].n[j]][list[n1].n[k]]+mems[list[n2].n[p]]>max)max=memf[s%2][list[a[i-2]].n[j]][list[n1].n[k]]+mems[list[n2].n[p]];
			}
		}
	}
	cout<<max<<endl;
	return 0;
}