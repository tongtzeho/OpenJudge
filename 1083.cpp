#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int testsum,i,j,k,n,a[405],b[405],p;
	vector<int> v1,v2;
	cin>>testsum;
	for(i=1;i<=testsum;i++)
	{
		cin>>n;
		v1.clear();
		v2.clear();
		for(j=1;j<=n;j++)
		{
			cin>>a[j]>>b[j];
	        if(a[j]>b[j])
			{
			    a[j]^=b[j];
			    b[j]^=a[j];
			    a[j]^=b[j];
			}
			if(a[j]%2==0)a[j]--;
			if(b[j]%2==1)b[j]++;
		}
		for(j=1;j<=n;j++)
			for(k=j+1;k<=n;k++)
				if(a[j]>a[k]||(a[j]==a[k]&&b[j]>b[k]))
				{
					a[j]^=a[k];
					a[k]^=a[j];
					a[j]^=a[k];
					b[j]^=b[k];
					b[k]^=b[j];
					b[j]^=b[k];
				}
		v1.push_back(a[1]);
		v2.push_back(b[1]);
		for(j=2;j<=n;j++)
		{
			bool t=0;
			for(k=0;k<v2.size();k++)
				if(v2[k]<a[j])
				{
					if(!t)
					{
						t=1;
						p=k;
					}
					else if(v2[k]>v2[p])p=k;
				}
			if(t)v2[p]=b[j];
			else
			{
				v1.push_back(a[j]);
				v2.push_back(b[j]);
			}
		}
		cout<<10*v1.size()<<endl;
	}
	return 0;
}