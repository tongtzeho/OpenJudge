#include<iostream>
#include<string>
using namespace std;
struct DATA
{
	string st;
	int n,m;
}student[600],temp;
int main()
{
	int i,j,n;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		student[i].m=i;
		cin>>student[i].st>>student[i].n;
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(student[i].n<student[j].n||(student[i].n==student[j].n&&student[i].m>student[j].m))
			{
				temp=student[i];
				student[i]=student[j];
				student[j]=temp;
			}
	for(i=1;i<=n;i++)
		cout<<student[i].st<<endl;
	return 0;
}