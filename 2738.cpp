#include<iostream>
#include<cstring>
int max(int a,int b)
{
	if(a>b)return a;
	else return b;
}
using namespace std;
int main()
{
	int n,i,j,k,s1,s2,t1,t2,z1,z2,t,left,right;
	char c1[120],c2[120],c3[240],c4[240],c5[240];
	cin>>n;
	for(k=1;k<=n;k++)
	{
		for(j=0;j<=110;j++)
			c1[j]=c2[j]='0';
		cin>>c1>>c2;
		t1=0;
		t2=0;
		for(j=0;j<max(strlen(c1),strlen(c2));j++)
		{
			if(c1[j]=='.')
			{
				z1=j;
				t1=1;
			}
			if(c2[j]=='.')
			{
				z2=j;
				t2=1;
			}
			if(t1==1&&t2==1)break;
		}
		s1=strlen(c1)-z1-1;
		s2=strlen(c2)-z2-1;
		for(i=1;i<=s1+s2;i++)
		{
			c3[i]=i<=s2?'0':c1[strlen(c1)-i+s2];
			c4[i]=i<=s1?'0':c2[strlen(c2)-i+s1];
		}
		for(i=s1+s2+1;i<=s1+s2+z1+z2;i++)
		{
			c3[i]=c1[strlen(c1)-i+s2-1];
			c4[i]=c2[strlen(c2)-i+s1-1];
			if(c3[i]<48||c3[i]>57)c3[i]='0';
			if(c4[i]<48||c4[i]>57)c4[i]='0';
		}
		t=0;
		for(j=1;j<=s1+s2+z1+z2;j++)
		{
			t1=c3[j]+c4[j]-96;
			c5[j]=(t+t1)%10+48;;
			t=(t+t1)/10==1?1:0;
		}
		for(j=1; ;j++)
			if (c5[j]!='0')
			{
				left=j;
				break;
			}
		t=0;
		for(j=s1+s2+z1+z2;j>=left;j--)
		{
			if(c5[j]!='0'||j==s1+s2+1)t=1;
			if(j==s1+s2)cout<<'.';
			if(t==1)cout<<c5[j];
		}
		cout<<endl;
	}
	return 0;
}
		