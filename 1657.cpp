#include<iostream>
#include<cmath>
using namespace std;
int max(int x,int y)
{
	int result=x;
	if(y>x) result=y;
	return result;
}
int a(int x)
{
	int result=x>0?x:-x;
	return result;
}
int main()
{
	int t,wang,hou,ju,xiang,i,x1,x2,y1,y2;
	char c1[4],c2[4];
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>c1>>c2;
		x1=int(c1[0]);
		x2=int(c2[0]);
		y1=int(c1[1]);
		y2=int(c2[1]);
		//cout<<x1<<' '<<x2<<' '<<y1<<' '<<y2<<' ';
		wang=max(a(x1-x2),a(y1-y2));
		if (x1==x2&&y1==y2) hou=0;
		else if (a(x1-x2)==a(y1-y2)||x1==x2||y1==y2) hou=1;
		else hou=2;
		if (x1==x2&&y1==y2) ju=0;
		else if (x1==x2||y1==y2) ju=1;
		else ju=2;
		if (x1==x2&&y1==y2) xiang=0;
		else if (a(x1-x2)==a(y1-y2)) xiang=1;
		else if((a(x1-x2)%2)!=(a(y1-y2)%2)) xiang=-1;
		else xiang=2;
		cout<<wang<<' '<<hou<<' '<<ju<<' ';
		if (xiang>=0) cout<<xiang;
		else cout<<"Inf";
		cout<<endl;
	}
	return 0;
}
