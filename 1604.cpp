#include<iostream>
#include<iomanip>
using namespace std;
int mem[130000]={1,1,2,6,24,12,72};
int nonzero1(int n)
{
	while(n%10==0)
		n/=10;
	return n%10;
}
int nonzero(int n)
{
	if(mem[n]!=0)return mem[n];
	int result;
	result=nonzero(n-1)*n;
	while(result%10==0)
		result/=10;
	mem[n]=result%100000;
	return mem[n];
}
int main()
{
	int n;
	while(cin>>n)
		cout<<setw(5)<<n<<" -> "<<nonzero(n)%10<<endl;
	return 0;
}