#include<list>
#include<iostream>
#include<string>
using namespace std;
template<class T>
void listout(T first,T last,int size)
{
	for( ;first!=last;first++)
	{
		size--;
		cout<<(*first);
		if(size!=0)cout<<" ";
	}
	cout<<endl;
}
int main()
{
	list<int> lst[10000];
	int n,i,j,x,y;
	string msg;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>msg;
		if(msg=="new")cin>>x;
		else if(msg=="add")
		{
			cin>>x>>y;
			lst[x].push_back(y);
		}
		else if(msg=="merge")
		{
			cin>>x>>y;
			lst[x].merge(lst[y]);
		}
		else if(msg=="unique")
		{
			cin>>x;
			lst[x].sort();
			lst[x].unique();
		}
		else if(msg=="out")
		{
			cin>>x;
			lst[x].sort();
			if(lst[x].size()==0)cout<<endl;
			else
			{
			    listout(lst[x].begin(),lst[x].end(),lst[x].size());
			}
		}
	}
	return 0;
}