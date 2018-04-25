#include<iostream>
#include<cstring>
using namespace std;
int *a;
void search(int n,int k,int m)
{
	int i,j;
	if(m==0)return;
	for(i=n;i<=k;i++)
		for(j=i-1;a[i]==2&&j>=0;j--)
			if(a[j]==1)
			{
				a[i]=a[j]=0;
				cout<<j+1;
				if(m-1!=0)cout<<' ';
				search(i,k,m-1);
			}
}
int main()
{
	char input[300];
	int i,k;
	while(cin>>k)
	{
	    cin>>input;
	    a=new int[k];
	    for(i=0;i<k;i++)
		    a[i]=(input[i]==input[0])?1:2;
	    search(0,k,k/2);
	    cout<<endl;
	}
	return 0;
}