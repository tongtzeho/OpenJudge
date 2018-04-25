#include<iostream>
#include<vector>
#define START 6725601
using namespace std;
const int k7[9]={1,7,49,343,2401,16807,117649,823543,5764801};
unsigned char a[40400001];
int x1,y1,color[9],v1[2][120001],v3[2][120001],v1size=0,v2size,v3size=0,v4size;
vector<int> vr;
void calc(const int x)
{
	vr.clear();
	int i,j,mx=x;
	for(i=0;i<=8;i++)
	{
		color[i]=mx%7;
		if(color[i]==0)j=i;
		mx/=7;
	}
	if(j<=5)
	{
		if(color[j+3]==1)vr.push_back(x-color[j+3]*k7[j+3]+6*k7[j]);
		else if(color[j+3]==6)vr.push_back(x-color[j+3]*k7[j+3]+1*k7[j]);
		else if(color[j+3]==2)vr.push_back(x-color[j+3]*k7[j+3]+3*k7[j]);
		else if(color[j+3]==3)vr.push_back(x-color[j+3]*k7[j+3]+2*k7[j]);
		else if(color[j+3]==4)vr.push_back(x-color[j+3]*k7[j+3]+5*k7[j]);
		else if(color[j+3]==5)vr.push_back(x-color[j+3]*k7[j+3]+4*k7[j]);
	}
	if(j>2)
	{
		if(color[j-3]==1)vr.push_back(x-color[j-3]*k7[j-3]+6*k7[j]);
		else if(color[j-3]==6)vr.push_back(x-color[j-3]*k7[j-3]+1*k7[j]);
		else if(color[j-3]==2)vr.push_back(x-color[j-3]*k7[j-3]+3*k7[j]);
		else if(color[j-3]==3)vr.push_back(x-color[j-3]*k7[j-3]+2*k7[j]);
		else if(color[j-3]==4)vr.push_back(x-color[j-3]*k7[j-3]+5*k7[j]);
		else if(color[j-3]==5)vr.push_back(x-color[j-3]*k7[j-3]+4*k7[j]);
	}
	if(j%3!=0)
	{
		if(color[j-1]<=3)vr.push_back(x-color[j-1]*k7[j-1]+(color[j-1]+3)*k7[j]);
		else vr.push_back(x-color[j-1]*k7[j-1]+(color[j-1]-3)*k7[j]);
	}
	if(j%3!=2)
	{
		if(color[j+1]<=3)vr.push_back(x-color[j+1]*k7[j+1]+(color[j+1]+3)*k7[j]);
		else vr.push_back(x-color[j+1]*k7[j+1]+(color[j+1]-3)*k7[j]);
	}
}
int main()
{
	char c;
	int i,j,k,find=0,m,n;
	while(cin>>x1>>y1)
	{
		if(x1==0&&y1==0)return 0;
		v3size=find=0;
		for(i=0;i<40400001;i++)
			a[i]=0;
		for(i=0;i<=8;i++)
		{
			cin>>c;
			if(c=='E')color[i]=0;
			else if(c=='W')color[i]=1;
			else if(c=='B')color[i]=2;
			else color[i]=3;
		}
		v1[0][0]=START-k7[3*(y1-1)+x1-1];
		a[START-k7[3*(y1-1)+x1-1]]=1;
		v1size=1;
		for(i=0;i<512;i++)
		{
			int tmp=0;
			for(j=0;j<=8;j++)
				if(color[j]!=0)tmp+=(2*color[j]-((i>>j)&1))*k7[j];
			if(a[tmp]==0)
			{
				a[tmp]=2;
				v3[0][v3size]=tmp;
				v3size++;
			}
			else if(a[tmp]==1)find=1;
		}
		if(find)
		{
			cout<<0<<endl;
			continue;
		}
		for(k=1;k<=20;k++)
		{
			m=(k+1)%2;
			n=k%2;
			v2size=0;
			v4size=0;
			for(i=0;i<v1size;i++)
			{
				calc(v1[m][i]);
				for(j=0;j<vr.size();j++)
				{
					if(a[vr[j]]==0)
					{
						a[vr[j]]=1;
						v1[n][v2size]=vr[j];
						v2size++;
					}
					else if(a[vr[j]]==2&&!find)
					{
						if(k<=10)find=2*k-1;
						else find=k+10;
					}
				}
			}
			for(i=0;k<=10&&i<v3size;i++)
			{
				calc(v3[m][i]);
				for(j=0;j<vr.size();j++)
				{
					if(a[vr[j]]==0)
					{
						a[vr[j]]=2;
						v3[n][v4size]=vr[j];
						v4size++;
					}
					else if(a[vr[j]]==1&&!find)find=2*k;
				}
			}
			if(find)
			{
				cout<<find<<endl;
				break;
			}
			else
			{
				v1size=v2size;
				v3size=v4size;
			}
		}
		if(!find)cout<<"-1\n";
	}
}