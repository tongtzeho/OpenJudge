#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<stdlib.h>
using namespace std;

struct SUBSTR
{
	string st;
	int n;
}str[10000];

int cmp(const void *a, const void *b)
{
	return strcmp(((struct SUBSTR*)a)->st.c_str(),((struct SUBSTR*)b)->st.c_str());
}

int main()
{
	int total=0,i,j,k,l,temp;
	bool t;
	string st,tempsubstr;
	cin>>st;
	l=st.length();
	for(i=0;i<l;i++)
	{
		temp=total;
		for(j=0;j<l-i;j++)
		{
			t=0;
			tempsubstr=st.substr(j,i+1);
			for(k=temp;k<total;k++)
				if(str[k].st==tempsubstr)
				{
					t=1;
					str[k].n++;
					break;
				}
			if(!t)
			{
				str[total].n=1;
				str[total].st=tempsubstr;
				total++;
			}
		}
	}
	qsort(str,total,sizeof(str[0]),cmp);
	for(i=0;i<total;i++)
		if(str[i].n!=1)
		{
			printf("%s %d\n",str[i].st.c_str(),str[i].n);
		}
	return 0;
}
