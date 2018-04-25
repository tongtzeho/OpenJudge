#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
int main()
{
	char ch;
	int a[10]={0},i,j;
	while(cin.get(ch))
	{
		if(ch=='\n')
		{
			for(i=0;i<=9;i++)
				for(j=1;j<=a[i];j++)
					cout<<setw(4)<<i;
			cout<<endl;
			for(i=0;i<=9;i++)
				a[i]=0;
		}
		else if(ch>=48&&ch<=57) a[ch-48]++;
	}
	for(i=0;i<=9;i++)
		for(j=1;j<=a[i];j++)
			cout<<setw(4)<<i;
	return 0;
}