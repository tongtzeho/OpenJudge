#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,k,i,j,m;
	double house=200;
	while(cin>>n>>k)
	{
		i=0;
		m=0;
		house=200;
		while(i<=21)
		{
			i++;
			m+=n;
			if(m>=house)break;
			house*=(1+double(k)/100);
		}
		if(i<=20)cout<<i<<endl;
		else cout<<"Impossible\n";
	}
	return 0;
}