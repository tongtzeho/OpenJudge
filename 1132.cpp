#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	int posx,posy,i,j,k,l,n,map[40][40],p,q;
	char str[1400];
	cin>>n;
	for(k=1;k<=n;k++)
	{
		cout<<"Bitmap #"<<k<<endl;
		cin>>posx>>posy;
		for(j=0;j<1400;j++)
			str[j]='\0';
		for(j=0;j<=33;j++)
			for(i=0;i<=33;i++)
				map[j][i]=0;
		cin>>str;
		p=q=0;
		l=strlen(str)-1;
		for(i=0;i<l;i++)
		{
			if(str[i]=='E')
			{
				if(map[posx+1][posy]==0)p++;
				if(map[posx+1][posy+1]==0)q++;
				map[posx+1][posy]=1;
				map[posx+1][posy+1]=-1;
				posx++;
			}
			else if(str[i]=='W')
			{
				if(map[posx][posy]==0)q++;
				if(map[posx][posy+1]==0)p++;
				map[posx][posy]=-1;
				map[posx][posy+1]=1;
				posx--;
			}
			else if(str[i]=='N')
			{
				if(map[posx+1][posy+1]==0)p++;
				if(map[posx][posy+1]==0)q++;
				map[posx+1][posy+1]=1;
				map[posx][posy+1]=-1;
				posy++;
			}
			else
			{
				if(map[posx+1][posy]==0)q++;
				if(map[posx][posy]==0)p++;
				map[posx][posy]=1;
				map[posx+1][posy]=-1;
				posy--;
			}
		//	cout<<posx<<" "<<posy<<endl;
		}
		for(i=1;i<=32;i++)
		{
			for(j=1;j<=32;j++)
			{
				if((p>q&&map[j][33-i]==1)||(p<q&&map[j][33-i]==-1))cout<<"X";
				else cout<<".";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
