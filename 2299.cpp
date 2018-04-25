#include <stdio.h>

int n,a[500005];

long long cnt(const int x1,const int x2)
{
	if(x1==x2)return 0;
	int mid=(x1+x2)/2;
	long long ret=cnt(x1,mid)+cnt(mid+1,x2);
	int p1=x1,p2=mid+1;
	int *tmp=new int[x2-x1+3];
	int k=0;
	while(p1<=mid||p2<=x2)
	{
		if(p1<=mid&&(p2>x2||a[p1]<a[p2]))
		{
			tmp[k]=a[p1];
			p1++;
			k++;
		}
		else
		{
			tmp[k]=a[p2];
			p2++;
			k++;
			ret+=mid-p1+1;
		}
	}
	for(k=0;k<=x2-x1;k++)
		a[x1+k]=tmp[k];
	delete []tmp;
	return ret;
}

int main()
{
	int i;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)return 0;
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		printf("%lld\n",cnt(1,n));
	}
}