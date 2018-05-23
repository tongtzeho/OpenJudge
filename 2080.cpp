#include<iostream>
using namespace std;
int my[2940000]={2000,0},mm[2940000]={1,0},md[2940000]={1,0},b=0,daynum[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void next()
{
	if ((my[b]%4==0&&my[b]%100!=0)||(my[b]%400==0)) daynum[2]=29;
	else daynum[2]=28;
	b++;
	mm[b]=mm[b-1];
	my[b]=my[b-1];
	md[b]=md[b-1]+1;
	if(md[b]>daynum[mm[b-1]])
	{
		md[b]=1;
		mm[b]=mm[b-1]+1;
	}
	if(mm[b]==13)
	{
		mm[b]=1;
		my[b]++;
	}
}
void print(int i)
{
	cout<<my[i]<<'-';
	if(mm[i]<10)cout<<0;
	cout<<mm[i]<<'-';
	if(md[i]<10)cout<<0;
	cout<<md[i]<<' ';
	if(i%7==0)cout<<"Saturday"<<endl;
	if(i%7==1)cout<<"Sunday"<<endl;
	if(i%7==2)cout<<"Monday"<<endl;
	if(i%7==3)cout<<"Tuesday"<<endl;
	if(i%7==4)cout<<"Wednesday"<<endl;
	if(i%7==5)cout<<"Thursday"<<endl;
	if(i%7==6)cout<<"Friday"<<endl;
}
int main()
{
	int n;
	for(n=0;n<=2930000;n++)
		next();
	mm[1]=1;
	md[1]=2;
	while(1==1)
	{
		cin>>n;
		if(n==-1)return 0;
		print(n);
	}
}