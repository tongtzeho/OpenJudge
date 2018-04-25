#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class DNA
{
public:
	int inv;
	char str[60];
	void calc(const int length)
	{
		int i,j;
		inv=0;
		for(i=0;i<length;i++)
			for(j=i+1;j<length;j++)
				if(str[i]>str[j])inv++;
	}
}dna[120],temp;

int main()
{
	int i,j,m,n;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>dna[i].str;
		dna[i].calc(n);
	}
	for(i=1;i<=m;i++)
		for(j=i+1;j<=m;j++)
			if(dna[i].inv>dna[j].inv)
			{
				temp=dna[i];
				dna[i]=dna[j];
				dna[j]=temp;
			}
	for(i=1;i<=m;i++)
		cout<<dna[i].str<<endl;
	return 0;
}