#include<iostream>
#include<cstring>
#include<string>
#include<stdlib.h>
using namespace std;

class DATA
{
public:
	bool isnum,use;
	int n;
}data[40];

int main()
{
	int dts,dtl,i,j,k,l;
	bool t;
	char input[40];
	while(cin.getline(input,40,'\n'))
	{
		l=strlen(input);
		dts=dtl=0;
		i=t=0;
		if(input[0]=='-')
		{
			dts++;
			data[dts].use=1;
			data[dts].isnum=1;
			data[dts].n=0;
			t=0;
		}
		while(i<l)
		{
			if(input[i]=='+'||input[i]=='-'||input[i]=='^')
			{
				dts++;
				data[dts].use=1;
				data[dts].isnum=0;
				if(input[i]=='+')data[dts].n=1;
				else if(input[i]=='-')data[dts].n=2;
				else data[dts].n=5;
				i++;
				t=0;
			}
			else if(input[i]=='x')
			{
				if(t)
				{
					dts++;
					data[dts].use=1;
					data[dts].isnum=0;
					data[dts].n=3;
				}
				dts++;
				data[dts].use=1;
				data[dts].isnum=1;
				data[dts].n=3;
				t=0;
				i++;
			}
			else
			{
				char tempnum[11];
				for(j=0;j<11;j++)
					tempnum[j]='\0';
				j=i;
				while(input[j]>='0'&&input[j]<='9')
				{
					tempnum[j-i]=input[j];
					j++;
				}
				i=j;
				t=1;
				dts++;
				data[dts].use=1;
				data[dts].isnum=1;
				data[dts].n=atoi(tempnum);
			}
		}
		dtl=dts;
		while(dtl>1)
		{
			for(i=1;i<=dts;i++)
			{
				if(data[i].use==1&&data[i].isnum==0&&data[i].n==5)
				{
					for(j=i-1; ;j--)
						if(data[j].use==1&&data[j].isnum==1)break;
					for(k=i+1; ;k++)
						if(data[k].use==1&&data[k].isnum==1)break;
					data[i].use=data[k].use=0;
					int temp=1;
					for(l=1;l<=data[k].n;l++)
						temp*=data[j].n;
					data[j].n=temp;
					dtl-=2;
				}
			}
			for(i=1;i<=dts;i++)
			{
				if(data[i].use==1&&data[i].isnum==0&&data[i].n==3)
				{
					for(j=i-1; ;j--)
						if(data[j].use==1&&data[j].isnum==1)break;
					for(k=i+1; ;k++)
						if(data[k].use==1&&data[k].isnum==1)break;
					data[i].use=data[k].use=0;
					data[j].n*=data[k].n;
					dtl-=2;
				}
			}
			for(i=1;i<=dts;i++)
			{
				if(data[i].use==1&&data[i].isnum==0&&data[i].n<=2)
				{
					for(j=i-1; ;j--)
						if(data[j].use==1&&data[j].isnum==1)break;
					for(k=i+1; ;k++)
						if(data[k].use==1&&data[k].isnum==1)break;
					data[i].use=data[k].use=0;
					if(data[i].n==1)data[j].n+=data[k].n;
					else data[j].n-=data[k].n;
					dtl-=2;
				}
			}
		}
		for(i=1;i<=dts;i++)
			if(data[i].use==1&&data[i].isnum==1)cout<<data[i].n<<endl;
	}
	return 0;
}