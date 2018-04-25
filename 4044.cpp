#include<iostream>
#include<cstring>
#include<string>
using namespace std;
struct data
{
	int weight;
	string color;
}
*mouse,temp;
int main()
{
	int n,i,j;
	cin>>n;
	mouse=new data[n];
	for(i=0;i<n;i++)
		cin>>mouse[i].weight>>mouse[i].color;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			if(mouse[i].weight>mouse[j].weight)
			{
				temp=mouse[i];
				mouse[i]=mouse[j];
				mouse[j]=temp;
			}
		}
	for(i=0;i<n;i++)
		cout<<mouse[i].color<<endl;
	return 0;
}