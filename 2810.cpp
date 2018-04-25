#include<iostream>
using namespace std;
int main()
{
	int n,a,b,c,d;
	cin>>n;
	for(a=2;a<=n;a++)
		for(b=2;b<=a;b++)
			for(c=b;c<=a;c++)
				for(d=c;d<=a;d++)
					if(a*a*a==b*b*b+c*c*c+d*d*d)cout<<"Cube = "<<a<<", Triple = ("<<b<<','<<c<<','<<d<<")\n";
	return 0;
}