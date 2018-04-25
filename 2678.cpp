#include<iostream>
#include<string>
#include<cstring>
using namespace std;
bool zichuan(char c1[ ],char c2[ ])
{
	int i,j,t;
	for(i=0;i<=strlen(c2)-strlen(c1);i++)
	{
		t=1;
		for(j=0;j<strlen(c1);j++)
			if(c1[j]!=c2[i+j])t=0;
		if(t==1)return true;
		//t=1;
		//for(j=0;j<strlen(c1);j++)
		//	if(c1[strlen(c1)-j-1]!=c2[i+j])t=0;
		//if(t==1)return true;
	}
	return false;
}
int main()
{
	int t,n,i,j,k,l,minlength,minlengthposition,s,p,q,maxlength;
	char input[150],copy[150],ch[150][150],z[150];
	cin>>t;
	for(i=1;i<=t;i++)
	{
		n=2;
		minlength=200;
		maxlength=0;
		for(j=1;j<=n;j++)
		{
			cin>>input;
			if(strlen(input)>maxlength)maxlength=strlen(input);
			if(strlen(input)<minlength)
			{
				minlength=strlen(input);
				minlengthposition=j;
			}
			for(k=0;k<strlen(input);k++)
				ch[j][k]=input[k];
		}
		s=0;
		for(j=minlength;s==0&&j>=1;j--)
			for(k=0;s==0&&k<=minlength-j;k++)
			{
				for(l=0;l<j;l++)
					z[l]=ch[minlengthposition][k+l];
				z[j]='\0';
				s=1;
				for(l=1;l<=n;l++)
				{
					for(p=0;p<maxlength;p++)
						copy[p]=ch[l][p];
					if(zichuan(z,copy)==0)
					{
						s=0;
						break;
					}
				}
				if(s==1)cout<<j<<endl;
			}
		if(s==0)cout<<0<<endl;
		for(p=0;p<maxlength;p++)
			copy[p]='\0';
	}
	return 0;
}