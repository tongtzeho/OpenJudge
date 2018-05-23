#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	char ch1[10],ch2[10],z[5];
	int i,j,k,l,n,l1,l2,a[4][13]={0},b[4][13]={0},c[13]={0},w[13]={0},t[4]={0},s,m;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=12;j++)
			a[1][j]=b[1][j]=a[2][j]=b[2][j]=a[3][j]=b[3][j]=c[j]=w[j]=0;
		for(j=1;j<=3;j++)
		{
			cin>>ch1>>ch2>>z;
			l1=strlen(ch1);
			l2=strlen(ch2);
			for(k=0;k<l1;k++)
				a[j][ch1[k]-64]=1;
			for(k=0;k<l2;k++)
				b[j][ch2[k]-64]=1;
			if(z[0]=='e')t[j]=0;
			else if(z[0]=='d')t[j]=-1;
			else t[j]=1;
		}
		//for(j=1;j<=3;j++)
		//{
		//	for(k=1;k<=12;k++)
		//		cout<<a[j][k];
		//	cout<<' ';
		//	for(k=1;k<=12;k++)
		//		cout<<b[j][k];
		//	cout<<endl;
		//}
		for(j=1;j<=12;j++)
		{
			for(k=1;k<=12;k++)
				w[k]=0;
			w[j]=1;
			m=1;
			for(k=1;k<=3;k++)
			{
				s=0;
				for(l=1;l<=12;l++)
					s+=a[k][l]*w[l]-b[k][l]*w[l];
				//cout<<j<<' '<<w[j]<<' '<<s<<' '<<t[k]<<endl;
				if(s!=t[k])m=0;
				if(m==0)break;
			}
			if(m==1)
			{
				cout<<char(j+64)<<" is the counterfeit coin and it is heavy.\n";
				break;
			}
			for(k=1;k<=12;k++)
				w[k]=0;
			w[j]=-1;
			m=1;
			for(k=1;k<=3;k++)
			{
				s=0;
				for(l=1;l<=12;l++)
					s+=a[k][l]*w[l]-b[k][l]*w[l];
				//cout<<j<<' '<<w[j]<<' '<<s<<' '<<t[k]<<endl;
				if(s!=t[k])m=0;
				if(m==0)break;
			}
			if(m==1)
			{
				cout<<char(j+64)<<" is the counterfeit coin and it is light.\n";
				break;
			}
		}
	}
	return 0;
}