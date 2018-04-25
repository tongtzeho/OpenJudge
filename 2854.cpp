#include<iostream>
#include<cmath>
using namespace std;
int main( )
{
	float x,y;
	while(cin>>x>>y)
	{
		if ((x>=-1.0)&&(x<=1.0)&&(y>=-1.0)&&(y<=1.0)) cout<<"yes"<<endl;
	    else cout<<"no"<<endl;
	}
	return 0;
}