#include<iostream>
using namespace std;
int main()
{
	int i,j,k,t,n,a[20];
	while(1==1)
	{
		k=0;
		i=1;
		while(1==1)
		{
			cin>>a[i];
			if(a[1]==-1)return 0;
			if(a[i]==0) break;
			i++;
		}
		n=--i;
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				if(a[i]==a[j]*2||a[j]==a[i]*2) k++;
		cout<<k<<endl;
	}
}