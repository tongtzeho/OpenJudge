#include<iostream>
#include<cstring>
#include<string>
using namespace std;
char filename[500][100],dirname[500][100],temp[100];
int dirup[500]={0},dirdown[500]={0},dirleft[500]={0},dirright[500]={0},dirlast[500]={0},fileprev[500]={0},filenext[500]={0},filestart[500]={0},dirsum,filesum,dp,fp[500]={0};
void output(int x,int y,int z)
{
	int i,j,k;
	if(x==0)cout<<"ROOT\n";
	else 
	{
		for(i=1;i<=z;i++)
			cout<<"|     ";
		cout<<dirname[x]<<endl;
	}
	if(dirdown[x]!=0)
	{
		k=dirdown[x];
		do
		{
			output(k,0,z+1);
			k=dirright[k];
		}while(k!=0);
	}
	if(filestart[x]!=0)
	{
		for(i=1;i<=z;i++)
			cout<<"|     ";
		cout<<filename[filestart[x]]<<endl;
		k=filestart[x];
		while(k=filenext[k])
		{
			for(i=1;i<=z;i++)
			    cout<<"|     ";
		    cout<<filename[k]<<endl;
		}
	}
}
int main()
{
	int length,i,j,k,t=0,n=0;
	dirsum=filesum=dp=0;
	while(cin>>temp&&temp[0]!='#')
	{
		if(t==0)
		{
			n++;
			cout<<"DATA SET "<<n<<":\n";
			t=1;
		}
		if(temp[0]=='f')
		{
			filesum++;
			length=strlen(temp);
			for(i=0;i<length;i++)
				filename[filesum][i]=temp[i];
			if(fp[dp]==0)
			{
				fp[dp]=filestart[dp]=filesum;
			}
			else
			{
				if(strcmp(filename[fp[dp]],filename[filesum])<0)
				{
				    filenext[fp[dp]]=filesum;
				    fileprev[filesum]=fp[dp];
				    fp[dp]=filesum;
				}
				else if(strcmp(filename[filestart[dp]],filename[filesum])>0)
				{
					fileprev[filestart[dp]]=filesum;
					filenext[filesum]=filestart[dp];
					filestart[dp]=filesum;
				}
				else
				{
					i=filestart[dp];
					while(!(strcmp(filename[i],filename[filesum])<0&&strcmp(filename[filesum],filename[filenext[i]])<0))
						i=filenext[i];
					filenext[filesum]=filenext[i];
					fileprev[filesum]=fileprev[filenext[i]];
					filenext[i]=filesum;
					fileprev[filenext[filesum]]=filesum;
				}
			}
		}
		if(temp[0]=='d')
		{
			dirsum++;
			length=strlen(temp);
			for(i=0;i<length;i++)
				dirname[dirsum][i]=temp[i];
			if(dirdown[dp]==0)
			{
				dirlast[dp]=dirdown[dp]=dirsum;
				dirup[dirsum]=dp;
				dp=dirsum;
			}
			else
			{
				dirleft[dirsum]=dirlast[dp];
				dirright[dirlast[dp]]=dirsum;
				dirlast[dp]=dirsum;
				dirup[dirsum]=dp;
				dp=dirsum;
			}
		}
		if(temp[0]==']')
		{
			dp=dirup[dp];
		}
		if(temp[0]=='*')
		{
			output(0,0,0);
			t=0;
			cout<<endl;
			dirsum=filesum=dp=0;
			for(i=0;i<=500;i++)
				dirup[i]=dirdown[i]=dirleft[i]=dirright[i]=dirlast[i]=filenext[i]=fileprev[i]=filestart[i]=fp[i]=0;
		}
	}
	return 0;
}
