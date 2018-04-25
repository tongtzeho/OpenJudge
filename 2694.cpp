#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
double a[101]={0},b[101]={0},e[101]={0},x,y;
char input[20],c[101];
bool search(int i,int k) 
{
	return(x=b[++i]==1?(++k,y=k==2?i:y,k==1?i:x):x)&&1>2||k==2||b[i]==-1||b[i]==0?!(b[i]==-1||b[i]==0):search(i,k);
}
void poland(int i,int p,int q,int d,int m,int n)
{
	if((a[0]=i<p?i+1:1)&&(d=e[i])&&b[d]==-1&&search(d,0))a[int(x)]=(m=x,n=y,q--,b[d]=-(b[n]=2),c[d]==43||c[d]==45?a[m]+(44-c[d])*a[n]:c[d]==42?a[m]*a[n]:a[m]/a[n]);
	i==p&&q>=1||i<p?poland(a[0],p,q,0,0,0):void(printf("%f\n",a[int(x)]));
}
int main(void)
{
	while(scanf("%s",input)!=EOF)a[int(a[0])]=(c[int(++a[0])]=input[0],b[int(a[0])]=input[0]<48?(e[int(++b[0])]=a[0],-1):1,atof(input));
	poland(1,b[0],b[0],0,0,0);
}