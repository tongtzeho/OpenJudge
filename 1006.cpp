#include<iostream>
using namespace std;
int main()
{
	int p,e,i,d,j,k=0;
	while(cin>>p>>e>>i>>d&&d>=0)
	{
		k++;
		p%=23;
		e%=28;
		i%=33;
		for(j=i+33; ;j+=33)
			if((j-e)%28==0&&(j-p)%23==0)break;
		j=(j+21252-d)%21252;
		if(j==0)j=21252;
		cout<<"Case "<<k<<": the next triple peak occurs in "<<j<<" days.\n";
	}
	return 0;
}