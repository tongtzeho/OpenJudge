#include<iostream>
using namespace std;

unsigned int mem[31][31][31][31][31],a[6],n;

unsigned int f(int x1,int x2,int x3,int x4,int x5)
{
	if(mem[x1][x2][x3][x4][x5]!=0)return mem[x1][x2][x3][x4][x5];
	unsigned int ans=0;
	if(x1==1&&x2==0&&x3==0&&x4==0&&x5==0)return 1;
	if(n==5&&x5>0)ans+=f(x1,x2,x3,x4,x5-1);
	if(n>=4&&x4>0&&x4>x5)ans+=f(x1,x2,x3,x4-1,x5);
	if(n>=3&&x3>0&&x3>x4)ans+=f(x1,x2,x3-1,x4,x5);
	if(n>=2&&x2>0&&x2>x3)ans+=f(x1,x2-1,x3,x4,x5);
	if(x1>0&&x1>x2)ans+=f(x1-1,x2,x3,x4,x5);
	mem[x1][x2][x3][x4][x5]=ans;
	return ans;
}

int main()
{
	int i,j,q[6];
	while(cin>>n)
	{
		if(n==0)return 0;
		for(i=1;i<=5;i++)
			a[i]=0;
		for(i=1;i<=n;i++)
			cin>>a[i];
		for(q[1]=0;q[1]<=a[1];q[1]++)
			for(q[2]=0;q[2]<=a[2];q[2]++)
				for(q[3]=0;q[3]<=a[3];q[3]++)
					for(q[4]=0;q[4]<=a[4];q[4]++)
						for(q[5]=0;q[5]<=a[5];q[5]++)
							mem[q[1]][q[2]][q[3]][q[4]][q[5]]=0;
		for(i=n+1;i<=5;i++)
			a[i]=0;
		cout<<f(a[1],a[2],a[3],a[4],a[5])<<endl;
	}
}
