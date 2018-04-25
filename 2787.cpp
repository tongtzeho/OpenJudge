#include<iostream>
#include<cmath>
using namespace std;
double calc(double a,double b,int i)
{
	if(i==1) return a+b;
	if(i==2) return a-b;
	if(i==3) return a*b;
	if(i==4&&b!=0) return a/b;
	if(i==4&&b==0) return -90000000;
}
int main()
{
	double input[8]={0},r;
	int order[8]={0},o[5],i,j,k,l,t,s,mem[12][12][12][12]={0};
	while(1==1)
	{
		cin>>input[1]>>input[2]>>input[3]>>input[4];
		if (input[1]==0)break;
		o[1]=int(input[1]);
		o[2]=int(input[2]);
		o[3]=int(input[3]);
		o[4]=int(input[4]);
		for(i=1;i<=4;i++)
			for(j=i+1;j<=4;j++)
				if(o[i]>o[j])
				{
					s=o[i];
					o[i]=o[j];
					o[j]=s;
				}
		if (mem[o[1]][o[2]][o[3]][o[4]]!=0)
		{
			if(mem[o[1]][o[2]][o[3]][o[4]]==1) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
			continue;
		}
		order[1]=1;
		order[2]=2;
		order[3]=3;
		order[4]=4;
		t=0;
		for(i=1;i<=24;i++)
		{
			r=0;
			for(j=1;j<=4;j++)
			{
				for(k=1;k<=4;k++)
				{
					for(l=1;l<=4;l++)
					{
						r=calc(calc(calc(input[order[1]],input[order[2]],j),input[order[3]],k),input[order[4]],l);
						if(r>23.999&&r<24.001) t=1;
						r=calc(input[order[1]],calc(input[order[2]],calc(input[order[3]],input[order[4]],l),k),j);
						if(r>23.999&&r<24.001) t=1;
						r=calc(calc(input[order[1]],input[order[2]],j),calc(input[order[3]],input[order[4]],l),k);
						if(r>23.999&&r<24.001) t=1;
						r=calc(input[order[1]],calc(calc(input[order[2]],input[order[3]],k),input[order[4]],l),j);
						if(r>23.999&&r<24.001) t=1;
						if(t==1) break;
					}
				    if(t==1) break;
				}
			    if(t==1) break;
			}
            if(t==1) break;
			if (i<24)
			{
				if (order[3]<order[4]) 
				{
					s=order[3];
					order[3]=order[4];
					order[4]=s;
				}
				else if(order[2]!=4)
				{
					order[2]++;
					if(order[2]==order[1]) order[2]++;
					order[3]=(9-order[1]-order[2])/2;
					order[4]=(10-order[1]-order[2])/2+1;
					if (order[3]==order[1]||order[3]==order[2])
					{
						order[3]=1;
						order[4]=4;
					}
				}
				else
				{
					order[1]++;
					order[2]=1;
					order[3]=(9-order[1]-order[2])/2;
					order[4]=(10-order[1]-order[2])/2+1;
				}
			}
		}
		mem[o[1]][o[2]][o[3]][o[4]]=t+1;
		if(t==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

