#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	char ch1[120],ch2[120];
	int c1[27]={0},c2[27]={0},num1[200]={0},num2[200]={0},i,length;
	cin>>ch1>>ch2;
	length=strlen(ch1);
	if(strlen(ch2)!=length)
	{
		cout<<"NO";
		return 0;
	}
	for(i=0;i<length;i++)
	{
		c1[ch1[i]-64]++;
		c2[ch2[i]-64]++;
	}
	for(i=0;i<27;i++)
	{
		num1[c1[i]]++;
		num2[c2[i]]++;
	}
	for(i=0;i<200;i++)
	{
		if(num1[i]!=num2[i])
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}