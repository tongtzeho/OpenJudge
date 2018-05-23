#include<iostream>
using namespace std;
int main()
{
int a[6]={0},i,j,t;
while(cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5])
{t=1;
for(i=1;i<=5;i++)
for(j=i+1;j<=5;j++)
if(a[i]>a[j])
{
t=0;
a[i]^=a[j];
a[j]^=a[i];
a[i]^=a[j];
}
if(t==1)cout<<"Yes\n";
if(t==0)cout<<"No "<<a[1]<<' '<<a[2]<<' '<<a[3]<<' '<<a[4]<<' '<<a[5]<<endl;
}
return 0;
}