#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
int a1=0,a2=0,a3=0,a4=0,a5=0;
char ch;
while(cin.get(ch))
{
if(ch=='a')a1++;
else if(ch=='e')a2++;
else if(ch=='i')a3++;
else if(ch=='o')a4++;
else if(ch=='u')a5++;
}
cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" "<<a5;
return 0;
}