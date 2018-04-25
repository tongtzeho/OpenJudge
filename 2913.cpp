#include<iostream>
#include<cstring>
#include<string>
using namespace std;
char input[800];
int a[7]={4,9,6,2,8,7,3};
inline char turn(int n)
{
	int r;
	r=input[n]+a[n%7];
	if(r>122)r-=91;
	return char(r);
}
int main()
{
	cin.getline(input,700,'\n');
	int i;
	for(i=0;i<strlen(input);i++)
		cout<<turn(i);
	cout<<endl<<input;
	return 0;
}