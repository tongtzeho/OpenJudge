#include<iostream>
#include<cstring>
using namespace std;
int n,a[10]={0,1,2,3,4,5,6,7,8,9};
void next()
{
	int i,j,k,s,t;
	i=n;
	while(a[i-1]>a[i])
	{
		i--;
	}
	t=i;
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
int main()
{
	char input[10],ch[10]={'1'};
	int i,j,k,t=1;
	cin>>input;
	n=strlen(input);
	k=0;
	for(i=1;i<=n;i++)
		t*=i;
	for(i=97;i<=122;i++)
		for(j=0;j<=5;j++)
			if(input[j]==i)
			{
				k++;
				ch[k]=i;
			}
	while(t>0)
	{
		for(i=1;i<=n;i++)
			cout<<ch[a[i]];
		cout<<endl;
		next();
		t--;
	}
	return 0;
}