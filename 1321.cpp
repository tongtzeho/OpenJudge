#include<iostream>
using namespace std;
int b[10][10]={0},c[10],d[10]={0},e[10],h[10],sum,n,k;//a棋盘状态 b每列第几个#出现的位置 c放棋的列 d每列#的个数 f临时数组 g每列放棋的位置
void next()
{
	int i,s;
	s=k;
	while(c[s]==n-k+s)
		s--;
	c[s]++;
	for(i=s+1;i<=k;i++)
		c[i]=c[i-1]+1;
}
bool differ(int arr[ ])
{
	int i,j;
	for(i=1;i<=k;i++)
		for(j=i<5?6:i+1;j<=k;j++)
			if(arr[i]==arr[j]) return false;
	return true;
}
int main()
{
	int i,j,s,t,q[10];
	char ch;
	while(1==1)
	{
		sum=0;
		cin>>n>>k;
		if(n==-1)return 0;
		for(i=0;i<=8;i++)
			for(j=1;j<=8;j++)
			{
				b[i][j]=0;
				c[i]=i;
				d[i]=0;
			}
		cin.get(ch);
		for(i=1;i<=n;i++)
		{
			j=0;
			while(1==1)
			{
				j++;
				cin.get(ch);
				if(ch=='\n')break;
				if(ch=='#')
				{
					d[j]++;
					b[d[j]][j]=i;
				}
			}
		}
		while(c[0]==0)
		{
			for(i=1;i<=8;i++)
				e[i]=i>k?1:d[c[i]];
		    for(q[1]=1;q[1]<=e[1];q[1]++)
			    for(q[2]=1;q[2]<=e[2];q[2]++)
				{
					if(k>1&&b[q[2]][c[2]]==b[q[1]][c[1]])continue;
					for(q[3]=1;q[3]<=e[3];q[3]++)
					{
						if(k>2&&(b[q[3]][c[3]]==b[q[2]][c[2]]||b[q[3]][c[3]]==b[q[1]][c[1]]))continue;
					    for(q[4]=1;q[4]<=e[4];q[4]++)
						{
							if(k>3&&(b[q[4]][c[4]]==b[q[3]][c[3]]||b[q[4]][c[4]]==b[q[2]][c[2]]||b[q[4]][c[4]]==b[q[1]][c[1]]))continue;
							for(q[5]=1;q[5]<=e[5];q[5]++)
							{
							    if(k>4&&(b[q[5]][c[5]]==b[q[3]][c[3]]||b[q[5]][c[5]]==b[q[2]][c[2]]||b[q[5]][c[5]]==b[q[1]][c[1]]||b[q[5]][c[5]]==b[q[4]][c[4]]))continue;
								for(q[6]=1;q[6]<=e[6];q[6]++)
								    for(q[7]=1;q[7]<=e[7];q[7]++)
									    for(q[8]=1;q[8]<=e[8];q[8]++)
										{
											for(i=1;i<=k;i++)
												h[i]=b[q[i]][c[i]];
											if(differ(h))sum++;
										}
							}
						}
					}
				}
			next();
		}
		cout<<sum<<endl;
	}
}