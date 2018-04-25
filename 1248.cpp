#include<iostream>
#include<string>
using namespace std;
int order[6],length,num[13]={0};
int calc()
{
	int v=num[order[1]],w=num[order[2]],x=num[order[3]],y=num[order[4]],z=num[order[5]];
	return v-w*w+x*x*x-y*y*y*y+z*z*z*z*z;
}
bool next()
{
	bool b[7][14]={0},t=0;
	int i,j,k;
	for(i=2;i<=5;i++)
		for(j=1;j<i;j++)
			b[i][order[j]]=1;
	for(i=5;i>=1;i--)
	{
		k=order[i]+1;
		while(k<=length&&b[i][k])
			k++;
		if(k<=length)
		{
			t=1;
			order[i]=k;
			b[i][k]=1;
			k=1;
			for(j=i+1;j<=5;j++)
			{
				while(b[i][k])
					k++;
				b[i][k]=1;
				order[j]=k;
			}
			return 1;
		}
	}
	return 0;
}
int main()
{
	string str;
	int i,j,n;
	while(cin>>n>>str)
	{
		if(n==0&&str=="END")return 0;
		length=str.length();
		for(i=0;i<length;i++)
			num[i+1]=str[i]-'A'+1;
		for(i=1;i<=length;i++)
			for(j=i+1;j<=length;j++)
				if(num[i]<num[j])
				{
					num[i]^=num[j];
					num[j]^=num[i];
					num[i]^=num[j];
				}
		for(i=1;i<=5;i++)
			order[i]=i;
		bool t=0;
		do
		{
			if(n==calc())
			{
				t=1;
				for(i=1;i<=5;i++)
					cout<<char(num[order[i]]+64);
				cout<<endl;
				break;
			}
		}
		while(next());
		if(!t)cout<<"no solution\n";
	}
}