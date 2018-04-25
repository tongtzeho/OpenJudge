#include<iostream>
using namespace std;
int main()
{
	int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int n,month1,day1,num,month2,day2,count,i,j,d;
	cin>>n;
    for(i=1;i<=n;i++)
	{
		cin>>month1>>day1>>num>>month2>>day2;
		count=0;
		if(month1==month2) count=day2-day1+1;
		else
		{
			count=day[month1]-day1+1+day2;
			for(j=month1+1;j<month2;j++)
				count+=day[j];
		}
		d=1;
		for(j=1;j<count;j++)
			d*=2;
		num*=d;
		cout<<num<<endl;
	}
	return 0;
}
			