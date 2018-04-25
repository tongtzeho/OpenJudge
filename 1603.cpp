#include<iostream>
#include<vector>
using namespace std;
vector<int> v[21];
int main()
{
	bool b[21]={0};
	int i,j,k,m,p,p1,p2,testset=0;
	vector<int> v1,v2;
	while(cin>>m)
	{
		testset++;
		cout<<"Test Set #"<<testset<<endl;
		for(i=1;i<=20;i++)
			v[i].clear();
		for(j=1;j<=m;j++)
		{
			cin>>p;
			v[p].push_back(1);
			v[1].push_back(p);
		}
		for(i=2;i<=19;i++)
		{
		    cin>>m;
		    for(j=1;j<=m;j++)
			{
			    cin>>p;
			    v[p].push_back(i);
			    v[i].push_back(p);
			}
		}
		cin>>m;
		for(i=1;i<=m;i++)
		{
			cin>>p1>>p2;
			cout<<p1<<" to "<<p2<<": ";
			p=0;
			v1.clear();
			v1.push_back(p1);
			v2.clear();
			for(j=1;j<=20;j++)
				b[j]=0;
			b[p1]=1;
			while(!b[p2])
			{
				v2.clear();
				p++;
				for(j=0;j<v1.size();j++)
				{
					for(k=0;k<v[v1[j]].size();k++)
						if(!b[v[v1[j]][k]])
						{
							b[v[v1[j]][k]]=1;
							v2.push_back(v[v1[j]][k]);
						}
				}
				v1.clear();
				v2.swap(v1);
			}
			cout<<p<<endl;
		}
		cout<<endl;
	}
	return 0;
}