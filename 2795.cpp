#include<iostream>
#include<iomanip>
using namespace std;
struct data
{
	int n,v;
	double a;
}
*good,temp;
int main()
{
	int k,w,s,i,j,q,t;
	double value;
	cin>>k;
	for(i=1;i<=k;i++)
	{
		cin>>w>>s;
		good=new data[s+1];
		for(j=1;j<=s;j++)
		{
			cin>>good[j].n>>good[j].v;
			good[j].a=double(good[j].v)/good[j].n;
		}
		for(j=1;j<=s;j++)
			for(q=j+1;q<=s;q++)
				if(good[j].a<good[q].a)
				{
					temp=good[j];
					good[j]=good[q];
					good[q]=temp;
				}
		value=0;
		t=0;
		for(j=1;j<=s;j++)
		{
			if(t+good[j].n<=w)
			{
				t+=good[j].n;
				value+=good[j].v;
			}
			else
			{
				value+=good[j].v*double(w-t)/double(good[j].n);
				break;
			}
		}
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<value<<endl;
		delete good;
	}
	return 0;
}