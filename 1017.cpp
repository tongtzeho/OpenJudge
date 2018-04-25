#include<iostream>
#include<cmath>
using namespace std;
int max(int a,int b)
{
	int result=a;
	if(b>a) result=b;
	return result;
}
int min(int a,int b)
{
	int result=a;
	if(b<a) result=b;
	return result;
}
int tianhuaban(int a,int b)
{
	int result=a/b;
	if(a%b!=0&&a>0) result++;
	if (result<0) result=0;
	return result;
}
int main()
{
	int i,j,k=0,x,y,z,sum=0,a,b,c,d,e,f,t;
	while(1==1)
	{
		cin>>a>>b>>c>>d>>e>>f;
		k++;
		if(a+b+c+d+e+f==0) break;
		sum=0;
		sum+=(f+e+d+c/4);
		a=max(0,a-11*e);
		t=max(0,20*d-4*b);
		a=max(0,a-t);
		b=max(0,b-5*d);
		c=c%4;
		if(c==0) sum+=(tianhuaban(b*4+a,36));
		if(c==1) sum+=max(tianhuaban(b*4+a-9,36),1+tianhuaban(b-5,9));
		if(c==2)
		{
			x=max(1+tianhuaban(b*4+a-18,36),1+tianhuaban(b-3,9));
			y=max(2+tianhuaban(b*4+a-18,36),2+tianhuaban(b-10,9));
            sum+=min(x,y);
		}
		if(c==3)
		{
			x=max(1+tianhuaban(b*4+a-9,36),1+tianhuaban(b-1,9));
			y=max(2+tianhuaban(b*4+a-9,36),2+tianhuaban(b-8,9));
			z=max(3+tianhuaban(b*4+a-9,36),3+tianhuaban(b-15,9));
			sum+=min(min(x,y),z);
		}
		cout<<sum<<endl;
	}
	return 0;
}
