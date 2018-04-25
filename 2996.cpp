#include<iostream>
using namespace std;

class NUMBER
{
	int n,*a;
public:
	NUMBER(const int n_)
	{
		n=n_;
		a=new int[n+1];
		for(int i=1;i<=n;i++)
			cin>>a[i];
	}
	void next()
	{
		int i=n,j,k,s,t;
		while(a[i-1]>a[i])
			i--;
		t=i;
		if(t==1)
		{
		    for(i=1;i<=n;i++)
			    a[i]=i;
		    return;
		}
	    for(j=i;j<=n;j++)
		    if(a[j]<a[t]&&a[j]>a[i-1])t=j;
	    s=a[i-1];
	    a[i-1]=a[t];
	    a[t]=s;
	    for(j=i;j<=n;j++)
		    for(k=j+1;k<=n;k++)
			    if(a[j]>a[k])
				{
				    s=a[j];
				    a[j]=a[k];
				    a[k]=s;
				}
	}
	void output()
	{
		for(int i=1;i<n;i++)
			cout<<a[i]<<" ";
		cout<<a[n];
	}
};

int main()
{
	int n,k,i;
	cin>>n>>k;
	NUMBER num(n);
	for(i=1;i<=k;i++)
		num.next();
	num.output();
	return 0;
}
