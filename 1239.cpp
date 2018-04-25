#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int mem[100][100];
vector<int> tmp,best;
string str;

int magnitude(const int x,const int y)
{
	int i=x;
	while(str[i]=='0'&&i<=y)
	{
		i++;
	}
	return y-i+1;
}

int larger(const int x1,const int y1,const int x2,const int y2)
{
	int i1=x1,i2=x2,i;
	while(str[i1]=='0'&&i1<y1)
	{
		i1++;
	}
	while(str[i2]=='0'&&i2<y2)
	{
		i2++;
	}
	if(y1-i1!=y2-i2)
	{
		if(y1-i1>y2-i2)return 1;
		else return -1;
	}
	for(i=i1;i<=y1;i++)
		if(str[i]<str[i-i1+i2])return -1;
		else if(str[i]>str[i-i1+i2])return 1;
	return 0;
}

bool better()
{
	if(best.empty())return 1;
	int len=str.length();
	if(magnitude(tmp[0]+1,len-1)<magnitude(best[0]+1,len-1))return 1;
	else if(magnitude(best[0]+1,len-1)<magnitude(tmp[0]+1,len-1))return 0;
	int i=tmp.size(),j=best.size(),x1,x2,y1,y2;
	while(i>=0&&j>=0)
	{
		if(i>0)y1=tmp[i-1];
		else y1=len-1;
		if(j>0)y2=best[j-1];
		else y2=len-1;
		if(i==tmp.size())x1=0;
		else x1=tmp[i]+1;
		if(j==best.size())x2=0;
		else x2=best[j]+1;
		i--;
		j--;
		int result=larger(x1,y1,x2,y2);
		if(result==1)return 1;
		else if(result==-1)return 0;
	}
	return 0;
}

void substitute()
{
	best.clear();
	best=tmp;
}

void find_answer(const int x,const int y)
{
	if(mem[x][y]>20)return;
	int i;
	if(larger(x+1,y,0,x)==1)
	{
		if(better())substitute();
	}
	for(i=x-1;i>=0;i--)
	{
		if(larger(i+1,x,x+1,y)>=0)break;
		tmp.push_back(i);
		find_answer(i,x);
		tmp.pop_back();
	}
	mem[x][y]++;
}

int main()
{
	int i,j,k;
	while(cin>>str)
	{
		if(str.length()==1&&str[0]=='0')return 0;
		for(j=0;j<=82;j++)
			for(k=0;k<=82;k++)
				mem[j][k]=0;
		tmp.clear();
		best.clear();
		int len=str.length();
		for(i=len-2;i>=0;i--)
		{
			tmp.clear();
			tmp.push_back(i);
			if(!best.empty()&&magnitude(i+1,len-1)>magnitude(best[0]+1,len-1))break;
			else
			{
				find_answer(i,len-1);
			}
		}
		sort(best.begin(),best.end());
		j=0;
		if(best.empty()||(magnitude(best[0]+1,len-1)==magnitude(0,len-1)&&larger(0,len-1,0,best[0])))cout<<str;
		else
		{
			for(i=0;i<len;i++)
			{
				cout<<str[i];
				if(j<best.size()&&i==best[j])
				{
					cout<<",";
					j++;
				}
			}
		}
		cout<<endl;
	}
}
