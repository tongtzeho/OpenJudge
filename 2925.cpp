#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;

bool mod7(char *str)
{
	if(strlen(str)<9)
	{
		int k=atof(str);
		return k%7==0;
	}
	int l=strlen(str),i;
	char ch1[40],ch2[40],ch3[40];
	for(i=0;i<l;i++)
		ch1[i]=ch2[i]=ch3[i]='0';
	for(i=0;i<=2;i++)
		ch2[i]=str[l-1-i];
	for(i=0;i<l-3;i++)
		ch1[i]=str[l-4-i];
	int m=0,n,p,q;
	for(i=0;i<l;i++)
	{
		p=ch1[i]-'0'+m;
		q=ch2[i]-'0';
		if(p<q)
		{
			m=-1;
			p+=10;
		}
		else m=0;
		n=p-q;
		ch3[i]=n+'0';
	}
	for(i=l-1;i>=0;i--)
		if(ch3[i]!='0')break;
	for(m=0;m<l;m++)
		str[m]='\0';
	for(m=0;m<=i;m++)
		str[m]=ch3[i-m];
	return mod7(str);
}

int main()
{
	char str[40];
	int i,j,k,l;
	bool t[11]={0};
	while(1)
	{
		for(i=0;i<40;i++)
			str[i]='\0';
		cin.getline(str,40,'\n');
		if(str[0]=='-')return 0;
		for(i=1;i<10;i++)
			t[i]=0;
		l=strlen(str);
		k=str[l-1]-'0'+10*(str[l-2]-'0')+100*(str[l-3]-'0');
		if(k%2==0)t[2]=1;
		if(k%4==0)t[4]=1;
		if(k%8==0)t[8]=1;
		if(k%5==0)t[5]=1;
		k=0;
		for(i=0;i<l;i++)
			k+=(str[i]-'0');
		if(k%3==0)t[3]=1;
		if(k%9==0)t[9]=1;
		if(t[2]&&t[3])t[6]=1;
		t[7]=mod7(str);
		t[0]=0;
		for(i=2;i<=9;i++)
			if(t[i])
			{
				t[0]=1;
				cout<<i<<" ";
			}
		if(!t[0])cout<<"none";
		cout<<endl;
	}
}