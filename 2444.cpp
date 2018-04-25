#include<iostream>
#include<stdio.h>
using namespace std;

long long abs(const long long a)
{
	if(a>0)return a;
	return -a;
}

/*
__int64 abs(const __int64 a)
{
	if(a>0)return a;
	return -a;
}
*/
class MATRIX
{
public:
	int a;
	long long s;
//	__int64 s;
	MATRIX()
	{
		s=a=0;
	}
}**mat;

int main()
{
	int r,c,i,j;
	long long s,p1,p2,p3,p4,x,y,z,k;
//	__int64 s,p1,p2,p3,p4,x,y,z,k;
	while(1)
	{
		cin>>r>>c;
		if(r==c&&r==0)return 0;
		mat=new MATRIX*[r+1];
		s=2147481647;
		for(i=0;i<=r;i++)
		{
			mat[i]=new MATRIX[c+1];
			if(i!=0)
			{
				for(j=1;j<=c;j++)
				{
					cin>>mat[i][j].a;
					mat[i][j].s=mat[i][j-1].s+mat[i][j].a;
				}
				for(j=1;j<=c;j++)
					mat[i][j].s+=mat[i-1][j].s;
			}
		}
		for(i=1;i<r;i++)
			for(j=1;j<c;j++)
			{
				p1=mat[i][j].s;
				p2=mat[i][c].s-p1;
				p3=mat[r][j].s-p1;
				p4=mat[r][c].s-p1-p2-p3;
				x=p1;
				y=p2;
				z=p3+p4;
				k=abs(x-y)+abs(y-z)+abs(x-z);
				if(k<s)s=k;
				x=p1;
				y=p3;
				z=p2+p4;
				k=abs(x-y)+abs(y-z)+abs(x-z);
				if(k<s)s=k;
				x=p1+p2;
				y=p3;
				z=p4;
				k=abs(x-y)+abs(y-z)+abs(x-z);
				if(k<s)s=k;
				x=p1+p3;
				y=p2;
				z=p4;
				k=abs(x-y)+abs(y-z)+abs(x-z);
				if(k<s)s=k;
			}
		for(i=1;i<r-1;i++)
			for(j=i+1;j<r;j++)
			{
				x=mat[i][c].s;
				y=mat[j][c].s-x;
				z=mat[r][c].s-x-y;
				k=abs(x-y)+abs(y-z)+abs(x-z);
				if(k<s)s=k;
			}
		for(i=1;i<c-1;i++)
			for(j=i+1;j<c;j++)
			{
				x=mat[r][i].s;
				y=mat[r][j].s-x;
				z=mat[r][c].s-x-y;
				k=abs(x-y)+abs(y-z)+abs(x-z);
				if(k<s)s=k;
			}
	//	printf("%I64u\n",s);
		cout<<s<<endl;
		for(i=0;i<=r;i++)
			delete []mat[i];
		delete []mat;
	}
}