#include<iostream>
#include<cstring>
#include<string>
#include<stdlib.h>
#include<iomanip>
using namespace std;
int a[10000000]={0};
inline int turn(char c)
{
	if(c=='-')return -1;
	if(c=='0')return 0;
	if(c=='1')return 1;
	if(c=='A'||c=='B'||c=='C'||c=='2')return 2;
	if(c=='D'||c=='E'||c=='F'||c=='3')return 3;
	if(c=='G'||c=='H'||c=='I'||c=='4')return 4;
	if(c=='J'||c=='K'||c=='L'||c=='5')return 5;
	if(c=='M'||c=='N'||c=='O'||c=='6')return 6;
	if(c=='P'||c=='R'||c=='S'||c=='7')return 7;
	if(c=='T'||c=='U'||c=='V'||c=='8')return 8;
	if(c=='W'||c=='X'||c=='Y'||c=='9')return 9;
}
int comp(const void * a, const void * b)
{
     return *(int*)a - *(int*)b;
}
int main()
{
	int i,n,t,k,r=0,m=0,s,*b;
	char ch;
	cin>>n;
	b=new int[n+1];
	cin.get();
	for(i=1;i<=n;i++)
	{
		t=10000000;
		s=0;
		while(cin.get(ch)&&ch!='\n')
		{
			k=turn(ch);
			if(k>=0)
			{
				t/=10;
				s+=k*t;
			}
		}
		a[s]++;
		if(a[s]>1)r=1;
		if(a[s]==2)
		{
			m++;
			*(b+m)=s;
		}
	}
	if(r==0)cout<<"No duplicates.\n";
	else
	{
		qsort(b,m+1,sizeof(int),comp);
	    for(i=1;i<=m;i++)
		    if(a[*(b+i)]>1)cout<<setfill('0')<<setw(3)<<(*(b+i))/10000<<'-'<<setw(4)<<(*(b+i))%10000<<' '<<a[*(b+i)]<<endl;
	}
	return 0;
}