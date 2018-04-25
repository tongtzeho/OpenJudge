#include<iostream>
using namespace std;
int main()
{
	int sum[300]={0},i;
	char ch;
	while(cin.get(ch))
	{
		if(ch=='\n')
		{
			for(i=48;i<=57;i++)
			{
				if(sum[i]>0)
				{
					cout<<i-48<<':'<<sum[i]<<endl;
				}
				sum[i]=0;
			}
		}
		else sum[ch]++;
	}
	return 0;
}