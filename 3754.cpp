#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	char str1[300],str2[300];
	int l1,l2,i,j,k=0,m=0;
	while(cin>>str1>>str2)
	{
		if(strlen(str1)==1||strlen(str2)==1)return 0;
		l1=strlen(str1);
		l2=strlen(str2);
		m=0;
		for(i=0;i<l1;i++)
			for(j=0;j<l2;j++)
			{
				k=0;
				while(str1[(i+k)%l1]==str2[(j+k)%l2]&&k<l1&&k<l2)
					k++;
				if(k>m)m=k;
			}
		cout<<m<<endl;
	}
}