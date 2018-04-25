#include<iostream>
using namespace std;
int main()
{
	int i,j,k,m,n,t,kill,kill2,p,mem[14]={0};
	while(1==1)
	{
		cin>>k;
		if(k==0) break;
		m=k;
		if (mem[k]!=0) m=mem[k]-1;
		while(1==1)
		{
			m++;
			if(m%(2*k)>0&&m%(2*k)<=k) m+=k;
			p=1;
			t=1;
			kill2=m%(2*k);
			if(kill2==0) kill2=2*k;
			for(i=2*k;i>k+1;i--)
			{
                p=p>kill2?p-kill2:i-kill2+p;
				kill2=m%(i-1);
				if(kill2==0) kill2=i-1;
				if(((kill2-p)*(kill2-(p+k-1)))<=0)
				{
					t=0;
					break;
				}
			}
			if(t==1)
			{
				mem[k]=m;
				cout<<m<<endl;
				break;
			}
		}
	}
	return 0;
}