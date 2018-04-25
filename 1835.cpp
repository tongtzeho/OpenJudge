#include<iostream>
#include<cstring>
#include<string>
using namespace std;
class Cdata
{
public:
	int c[3],p[3];
	void move(const int a,const int b)
	{
		int i,j,k,l,m;
		if(b==1)
		{
			for(i=0;i<3;i++)
				if(p[i]==1||p[i]==-1)
				{
					p[i]*=-1;
					break;
				}
		}
		else if(b==2||b==3)
		{
			for(i=0;i<3;i++)
				if(p[i]==3||p[i]==-3)break;
			if(i==0)
			{
				j=1;
				k=2;
			}
			else if(i==1)
			{
				j=2;
				k=0;
			}
			else if(i==2)
			{
				j=0;
				k=1;
			}
			l=b==2?1:3;
			for(m=1;m<=l;m++)
			{
				p[j]^=p[k];
				p[k]^=p[j];
				p[j]^=p[k];
				if(p[i]==3)p[k]*=-1;
				else p[j]*=-1;
			}
		}
		else if(b==4||b==5)
		{
			for(i=0;i<3;i++)
				if(p[i]==0)break;
			if(i==0)
			{
				j=1;
				k=2;
			}
			else if(i==1)
			{
				j=2;
				k=0;
			}
			else if(i==2)
			{
				j=0;
				k=1;
			}
			l=b==4?1:3;
			for(m=1;m<=l;m++)
			{
				p[j]^=p[k];
				p[k]^=p[j];
				p[j]^=p[k];
				if(p[j]*p[k]<0)
				{
					if(p[j]==1||p[j]==-1)p[j]*=-1;
					else if(p[k]==1||p[k]==-1)p[k]*=-1;
				}
				else
				{
					if(p[j]==3||p[j]==-3)p[j]*=-1;
					else if(p[k]==3||p[k]==-3)p[k]*=-1;
				}
			}
		}
		for(i=0;i<3;i++)
			if(p[i]==1||p[i]==-1)break;
		c[i]+=a*p[i];
	}
}
pos;
int main()
{
	int datatotal,pacetotal,i,j,k,l;
	char ch[40];
	cin>>datatotal;
	for(i=1;i<=datatotal;i++)
	{
		cin>>pacetotal;
		pos.c[0]=pos.c[1]=pos.c[2]=pos.p[1]=0;
		pos.p[0]=1;
		pos.p[2]=3;
		for(j=1;j<=pacetotal;j++)
		{
			cin>>ch>>l;
			if(ch[0]=='f')k=0;
			else if(ch[0]=='b')k=1;
			else if(ch[0]=='l')k=2;
			else if(ch[0]=='r')k=3;
			else if(ch[0]=='u')k=4;
			else if(ch[0]=='d')k=5;
			pos.move(l,k);
		}
		cout<<pos.c[0]<<" "<<pos.c[1]<<" "<<pos.c[2]<<" ";
		for(j=0;j<3;j++)
			if(pos.p[j]==1||pos.p[j]==-1)break;
		cout<<j+(1-pos.p[j])/2*3<<endl;
	}
	return 0;
}
