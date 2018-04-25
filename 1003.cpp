#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double c,sum=0.5,s[300]={0,0,0.5,0.84,1.09},most=3;
	int i;
	while(cin>>c)
	{
		if(c==0)break;
		if(c<0.5) cout<<"1 card(s)"<<endl;
		if(c==0.5) cout<<"2 card(s)"<<endl;
		if(c>0.5)
		{
			i=2;
			sum=0.5;
			while(i<=600)
			{
				if(sum<=c&&(sum+double(1)/double(i+1))>c) break;
				i++;
				sum+=double(1)/i;
			}
			cout<<i<<" card(s)"<<endl;
		}
	}
	return 0;
}
