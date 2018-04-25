#include<iostream>
#include<vector>
using namespace std;
int l1,l2,m1[40],m2[40],maxlength,p,maxhighscore;
vector<int> v1,v2;
void f(const int x,const int y)
{
	int i=0,s=0,h=v1[x];
	while(x+i<v1.size()&&y+i<v2.size()&&v1[x+i]==v2[y+i])
	{
		s+=v1[x+i];
		i++;
	}
	if(i>maxlength)
	{
		maxlength=i;
		maxhighscore=h;
		p=x;
	}
	else if(i==maxlength&&h>maxhighscore)
	{
		maxhighscore=h;
		p=x;
	}
}
int main()
{
	int testsum,i,j,k;
	vector<int> v;
	cin>>testsum;
	for(i=1;i<=testsum;i++)
	{
		v.clear();
		v1.clear();
		v2.clear();
		cin>>l1>>l2;
		maxlength=maxhighscore=0;
		for(j=1;j<=l1;j++)
			cin>>m1[j];
		for(j=1;j<=l2;j++)
			cin>>m2[j];
		for(j=1;j<=l1;j++)
			for(k=j+1;k<=l1;k++)
				if(m1[j]<m1[k])
				{
					m1[j]^=m1[k];
					m1[k]^=m1[j];
					m1[j]^=m1[k];
				}
		for(j=1;j<=l2;j++)
			for(k=j+1;k<=l2;k++)
				if(m2[j]<m2[k])
				{
					m2[j]^=m2[k];
					m2[k]^=m2[j];
					m2[j]^=m2[k];
				}
		for(j=1;j<=l1;j++)
		{
			if(v1.empty())v1.push_back(m1[j]);
			else if(m1[j]!=v1.back())v1.push_back(m1[j]);
		}
		for(j=1;j<=l2;j++)
		{
			if(v2.empty())v2.push_back(m2[j]);
			else if(m2[j]!=v2.back())v2.push_back(m2[j]);
		}
		for(j=0;j<v1.size();j++)
			for(k=0;k<v2.size();k++)
				f(j,k);
		if(maxlength==0)cout<<"NONE\n";
		else
		{
			for(j=0;j<maxlength;j++)
				v.push_back(v1[p+j]);
			for(j=0;j<v.size();j++)
				for(k=j+1;k<v.size();k++)
					if(v[j]<v[k])
					{
						v[j]^=v[k];
						v[k]^=v[j];
						v[j]^=v[k];
					}
			cout<<v[0];
			for(j=1;j<v.size();j++)
				cout<<" "<<v[j];
			cout<<endl;
			for(j=0;j<v.size();j++)
				for(k=j+1;k<v.size();k++)
					if(v[j]%10>v[k]%10||(v[j]%10==v[k]%10&&v[j]>v[k]))
					{
						v[j]^=v[k];
						v[k]^=v[j];
						v[j]^=v[k];
					}
			cout<<v[0];
			for(j=1;j<v.size();j++)
				cout<<" "<<v[j];
			cout<<endl;
		}
	}
	return 0;
}
