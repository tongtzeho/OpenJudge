#include <iostream>

using namespace std;

int size,a[20],freq[13];
bool cake[40][40],ans;

bool put(const int x,const int y)
{
	if(ans)return 1;
	int i,j,k;
	for(i=2;i<=10;i++)
	{
		bool b=1;
		if(x+i-1>size||y+i-1>size)break;
		for(j=1;j<=i;j++)
			if(cake[x+i-1][y+j-1])
			{
				b=0;
				break;
			}
		if(!b)break;
		for(j=1;j<i;j++)
			if(cake[x+j-1][y+i-1])
			{
				b=0;
				break;
			}
		if(!b)break;
	}
	for(i=i-1;i>=1;i--)
	{
		if(ans)return 1;
		if(freq[i]>0)
		{
			bool found=0;
			for(j=1;j<=i;j++)
				for(k=1;k<=i;k++)
					cake[x+j-1][y+k-1]=1;
			freq[i]--;
			for(j=x;j<=size;j++)
			{
				for(k=1;k<=size;k++)
				{
					if(!cake[j][k])found=1;
					if(found)break;
				}
				if(found)break;
			}
			if(!found)ans=1;
			if(ans)return 1;
			put(j,k);
			if(ans)return 1;
			freq[i]++;
			for(j=1;j<=i;j++)
				for(k=1;k<=i;k++)
					cake[x+j-1][y+k-1]=0;
		}
	}
	if(ans)return 1;
	return 0;
}

int main()
{
	int t,n,i,j,q,area;
	cin>>t;
	for(q=1;q<=t;q++)
	{
		cin>>size>>n;
		area=0;
		for(i=1;i<=10;i++)
			freq[i]=0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			freq[a[i]]++;
			area+=a[i]*a[i];
		}
		for(i=1;i<=size;i++)
			for(j=1;j<=size;j++)
				cake[i][j]=0;
		ans=0;
		if(area==size*size)ans=put(1,1);
		if(ans)cout<<"KHOOOOB!"<<endl;
		else cout<<"HUTUTU!"<<endl;
	}
	return 0;
}