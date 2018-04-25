#include<iostream>
#include<algorithm>
using namespace std;

class CHANGE
{
public:
	int a;
	bool b; /* = b*a+c */
	long long c;
	CHANGE(){};
	CHANGE(const int A,const bool B,const long long C)
	{
		a=A;
		b=B;
		c=C;
	}
};

CHANGE cg[33][103],ans[103],tmp[103];
int n,m,k;

void calc(int st)
{
	int p=st-1,i;
	for(i=1;i<=n;i++)
	{
		int a=cg[p][i].a;
		long long c=cg[p][i].c;
		bool b=cg[p][i].b;
		cg[st][i].a=cg[p][a].a;
		cg[st][i].b=b&&cg[p][a].b;
		cg[st][i].c=c;
		if(b)cg[st][i].c+=cg[p][a].c;
	}
}

void get_ans()
{
	int i=1,j=1,q;
	while(j>0)
	{
		if(j&m)
		{
			for(q=1;q<=n;q++)
			{
				int a=ans[q].a;
				long long c=ans[q].c;
				bool b=ans[q].b;
				tmp[q].a=cg[i][a].a;
				tmp[q].b=b&&cg[i][a].b;
				tmp[q].c=c;
				if(b)tmp[q].c+=cg[i][a].c;
			}
			for(q=1;q<=n;q++)
				ans[q]=tmp[q];
		}
		i++;
		j<<=1;
	}
}

int main()
{
	int i,j;
	while(cin>>n>>m>>k)
	{
		if(n==0&&m==0&&k==0)return 0;
		for(i=1;i<=n;i++)
			ans[i]=cg[1][i]=CHANGE(i,1,0);
		for(i=1;i<=k;i++)
		{
			char ch;
			int t1,t2;
			cin>>ch;
			if(ch=='g')
			{
				cin>>t1;
				cg[1][t1].c++;
			}
			else if(ch=='e')
			{
				cin>>t1;
				cg[1][t1].b=0;
				cg[1][t1].c=0;
			}
			else if(ch=='s')
			{
				cin>>t1>>t2;
				swap(cg[1][t1],cg[1][t2]);
			}
		}
		i=1;
		for(i=2;i<=32;i++)
			calc(i);
		get_ans();
		for(i=1;i<=n;i++)
		{
			cout<<ans[i].c;
			if(i==n)cout<<endl;
			else cout<<" ";
		}
	}
}