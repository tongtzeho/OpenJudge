#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int mem[60001]={0},n,i;
	cout<<"PERFECTION OUTPUT\n";
	while(cin>>n)
	{
		if(n==0)
		{
			cout<<"END OF OUTPUT";
			return 0;
		}
		if(mem[n]==0)
		{
			for(i=2;i*i<=n;i++)
				if(n%i==0)
				{
					if(i*i<n)mem[n]+=(i+n/i);
					else mem[n]+=i;
					if(mem[n]>n)break;
				}
			if(n!=1)mem[n]++;
		}
		cout<<setw(5)<<n<<"  ";
		if(mem[n]==n)cout<<"PERFECT\n";
		else if(mem[n]>n)cout<<"ABUNDANT\n";
		else cout<<"DEFICIENT\n";
	}
}