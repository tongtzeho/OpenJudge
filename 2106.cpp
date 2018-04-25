#include<iostream>
using namespace std;
int exp[800]={0},lef,rig,k=0,l;
void search()
{
	int i;
	for(i=1;i<=k;i++)
	{
		if(exp[i]==6)lef=i;
		if(exp[i]==7)
		{
			rig=i;
			break;
		}
	}
	exp[lef]=exp[rig]=0;
	if(lef>0)l-=2;
}
void calc(int le,int ri,int t3)
{
	int i,j,a=0,b=0,c=0,t2=0,q,m=0;
	if(t3==0)
	    for(i=le+1;i<ri;i++)
		    if(exp[i]==3)
			    for(j=i+1; ;j++)
				    if(exp[j]==1||exp[j]==2)
					{
					    exp[i]=0;
					    exp[j]=3-exp[j];
					    l--;
					    break;
					}
	t3=1;
	for(i=le+1;i<ri;i++)
	{
		if(exp[i]==4||exp[i]==5)
		{
			m=1;
			break;
		}
	}
	if(m==0)return;
	for(q=4;q<=5;q++)
	{
	    t2=a=b=c=0;
		for(i=le+1;i<ri;i++)
			if(exp[i]==q)
			{
				b=exp[i];
				t2=1;
				l-=2;
				break;
			}
		for(j=i-1;j>le&&t2==1;j--)
			if(exp[j]==1||exp[j]==2)
			{
				a=exp[j];
				exp[j]=0;
				break;
			}
		for(j=i+1;j<ri&&t2==1;j++)
			if(exp[j]==1||exp[j]==2)
			{
				c=exp[j];
				exp[j]=0;
				break;
			}
		if(t2==1)break;
	}
	if(t2==0)return;
	if(b==4)exp[i]=(a==1&&c==1)?1:2;
	else exp[i]=(a==1||c==1)?1:2;
	calc(le,ri,t3);
}
int main()
{
	char ch;
	int i,m=0;
	while(cin.get(ch))
	{
		if(ch!='\n'&&ch!=32)
		{
			k++;
			if(ch=='V')exp[k]=1;
			if(ch=='F')exp[k]=2;
			if(ch=='!')exp[k]=3;
			if(ch=='&')exp[k]=4;
			if(ch=='|')exp[k]=5;
			if(ch=='(')exp[k]=6;
			if(ch==')')exp[k]=7;
		}
		if(ch=='\n')
		{
			l=k;
			m++;
		    cout<<"Expression "<<m<<": ";
			lef=rig=0;
			while(l>1)
			{
				lef=rig=0;
				search();
				if(lef==0&&rig==0)calc(0,k+1,0);
				else calc(lef,rig,0);
			}
			for(i=1;i<=k;i++)
				if(exp[i]==1||exp[i]==2)exp[i]==1?cout<<'V'<<endl:cout<<'F'<<endl;
			k=0;
		}
	}
	l=k;
	m++;
    cout<<"Expression "<<m<<": ";
	lef=rig=0;
	while(l>1)
	{
		lef=rig=0;
		search();
		if(lef==0&&rig==0)calc(0,k+1,0);
		else calc(lef,rig,0);
	}
	for(i=1;i<=k;i++)
	if(exp[i]==1||exp[i]==2)exp[i]==1?cout<<'V'<<endl:cout<<'F'<<endl;
	return 0;
}
