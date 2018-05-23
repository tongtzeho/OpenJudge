#include<iostream>
using namespace std;
int main()
{
int a,b;
cin>>a;
while(cin>>a>>b){
if(a==b&&a%2==1)cout<<a+b-1<<endl;
else if(a==b&&a%2==0)cout<<a+b<<endl;
else if(a-b==2&&a%2==0)cout<<a+b<<endl;
else if(a-b==2&&a%2==1)cout<<a+b-1<<endl;
else cout<<"No Number\n";}
return 0;
}