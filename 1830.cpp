#include<iostream>
#include<cmath>
using namespace std;
int k[31][31],b[31],x[31],n,k2[31],x2,sum=0,sum2=1;
void solve()
{
	int i,j,s,t;
	t=1;
	for(i=1;i<=n;i++)
	{
		s=0;
		for(j=1;j<=n;j++)
			s+=k[i][j]*x[j];
		if((s-b[i])%2!=0)
		{
			t=0;
			break;
		}
	}
	if(t==1)sum++;
	if(t==1)
	{
		for(i=1;i<=n;i++)
			cout<<x[i]<<' ';
		cout<<endl;
	}
	s=1;
	while(x[s]==1)
		s++;
	for(i=1;i<s;i++)
		x[i]=0;
	x[s]=1;
	if(x[n+1]==0)solve();
}
int main()
{
	int m,i,j,l,s,t,p,q,begin[31],end[31];
	cin>>m;
	for(i=1;i<=m;i++)
	{
		cin>>n;
		sum=0;
		x2=0;
		p=1;
		for(j=1;j<=n;j++)
		{
			cin>>begin[j];
			k2[j]=p;
			p*=2;
			x[j]=0;
			for(l=1;l<=n;l++)
				k[j][l]=j==l?1:0;
		}
		for(j=1;j<=n;j++)
		{
			cin>>end[j];
			b[j]=(begin[j]-end[j]+100)%2;
		}
		while(1==1)
		{
			cin>>s>>t;
			if(s==0)break;
			k[t][s]=1;
			p=1;
			for(j=1;j<s;j++)
				p*=2;
			k2[t]|=p;
		}
		//solve();
		for(j=1;j<=n;j++)
		{
			for(l=j;l<=n;l++)
				for(q=l+1;q<=n;q++)
					if(k2[l]<k2[q])
					{
						p=k2[l];
						k2[l]=k2[q];
						k2[q]=p;
						p=b[l];
						b[l]=b[q];
						b[q]=p;
					}
			for(l=j+1;l<=n;l++)
				if((k2[l]^k2[j])<k2[l]) 
				{
					k2[l]^=k2[j];
					b[l]^=b[j];
				}
		}
		sum2=1;
		j=n;
		while(k2[j]==0)
		{
			if(b[j]!=0)sum2=0;
			sum2*=2;
			j--;
		}
		if(sum2>0)cout<<sum2<<endl;
		else cout<<"Oh,it's impossible~!!"<<endl;
		//if(sum>0)cout<<sum<<endl;
		//else cout<<"Oh,it's impossible~!!"<<endl; 
	}
	return 0;
}