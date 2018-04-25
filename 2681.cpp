#include<iostream>
using namespace std;
int main()
{
	int i=0;
	char ch;
	while(cin.get(ch)&&ch!='\n')
		i++;
	cout<<i;
}