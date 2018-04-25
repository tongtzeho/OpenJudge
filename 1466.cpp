#include <iostream>
#include <cstring>

using namespace std;

int relatenum[503],ans,cur,n,maxpossi;
short relatepos[503][503];
bool choose[503];

void f(const int x)
{
	if(x>=n)
	{
		if(cur>ans)ans=cur;
		return;
	}
	if(maxpossi<=ans)return;
	if(choose[x])
	{
		maxpossi--;
		f(x+1);
		maxpossi++;
	}
	else if(relatenum[x]==0)
	{
		cur++;
		choose[x]=1;
		f(x+1);
		choose[x]=0;
		cur--;
	}
	else
	{
		int i;
		bool sta[503];
		for(i=0;i<n;i++)
			sta[i]=choose[i];
		cur++;
		choose[x]=1;
		for(i=0;i<relatenum[x];i++)
			choose[relatepos[x][i]]=1;
		f(x+1);
		for(i=0;i<n;i++)
			choose[i]=sta[i];
		cur--;
		maxpossi--;
		f(x+1);
		maxpossi++;
	}
}

int main()
{
	int i,j,k;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
		{
			cin>>j;
			char buf[5];
			cin.getline(buf,5,'(');
			cin>>k;
			cin.get();
			relatenum[i]=0;
			choose[i]=0;
			for(j=0;j<k;j++)
			{
				int tmp;
				cin>>tmp;
				relatepos[i][relatenum[i]]=tmp;
				relatenum[i]++;
			}
		}
		ans=cur=0;
		maxpossi=n;
		f(1);
		cout<<ans<<endl;
	}
	return 0;
}
