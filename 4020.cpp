#include<iostream>
#include<string>
using namespace std;
int main()
{
	bool b[5][15];
	int n,i,j,k;
	string st;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=4;j++)
			for(k=0;k<=13;k++)
				b[j][k]=0;
		for(j=1;j<=53;j++)
		{
			cin>>st;
			char c1=st[0],c2=st[st.length()-1];
			if(c1=='J')b[1][0]=1;
			else if(c1=='j')b[2][0]=1;
			else
			{
				int x,y;
				if(c1=='H')x=1;
				else if(c1=='S')x=2;
				else if(c1=='D')x=3;
				else if(c1=='C')x=4;
				if(c2=='2')y=2;
				else if(c2=='3')y=3;
				else if(c2=='4')y=4;
				else if(c2=='5')y=5;
				else if(c2=='6')y=6;
				else if(c2=='7')y=7;
				else if(c2=='8')y=8;
				else if(c2=='9')y=9;
				else if(c2=='0')y=10;
				else if(c2=='e')y=1;
				else if(c2=='k')y=11;
				else if(c2=='n')y=12;
				else y=13;
				b[x][y]=1;
			}
		}
		if(!b[1][0])cout<<"Joker\n";
		else if(!b[2][0])cout<<"joker\n";
		else
		{
			for(j=1;j<=4;j++)
				for(k=1;k<=13;k++)
					if(!b[j][k])
					{
						if(j==1)cout<<"Heart";
						else if(j==2)cout<<"Spade";
						else if(j==3)cout<<"Diamond";
						else cout<<"Club";
						if(k==1)cout<<"Ace\n";
						else if(k==11)cout<<"Jack\n";
						else if(k==12)cout<<"Queen\n";
						else if(k==13)cout<<"King\n";
						else cout<<k<<endl;
						break;
					}
		}
	}
	return 0;
}