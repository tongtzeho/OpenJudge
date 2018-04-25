#include<iostream>
using namespace std;
int main()
{
	const int s18[11]={0,18,198,1998,19998,199998,1999998,19999998,199999998,1999999998,2147481647};
	int m,n,i,j,k,l,d[50];
	bool t2;
	while(cin>>n&&n!=0)
	{
		for(i=0;i<=9;i++)
			if(s18[i]<n&&s18[i+1]>=n)break;
		k=s18[i]/2+s18[i+1]/2;
		if(n>k)
		{
			t2=1;
			m=n-k;
		}
		else
		{
			t2=0;
			m=n-s18[i];
		}
		l=i+1;
		for(j=1;j<=l;j++)
			d[j]=0;
		j=l;
		m--;
		while(m>0)
		{
			d[j]=m%10;
			m/=10;
			j--;
		}
		d[1]++;
		for(j=1;j<=l;j++)
			cout<<d[j];
		if(!t2)j=l-1;
		else j=l;
		for( ;j>=1;j--)
			cout<<d[j];
		cout<<endl;
	}
	return 0;
}