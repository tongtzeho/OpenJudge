#include<iostream>
using namespace std;
int main()
{
int n,*a,i;
cin>>n;
a=new int[n];
for(i=0;i<n;i++)
cin>>a[i];
for(i=n-1;i>0;i--)
cout<<a[i]<<' ';
cout<<a[0];
return 0;
}