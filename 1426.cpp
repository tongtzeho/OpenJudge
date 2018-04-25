#include <iostream>
#include <string>

using namespace std;

char answer[206][103]={0};
bool mem[206][103];
bool succeed=0;

bool find_answer(const int r,const int digit,const int modnum)
{
	if(r==0||succeed)
	{
		succeed=1;
		return 1;
	}
	if(digit>99||mem[r][digit])return 0;
	answer[modnum][digit]='1';
	answer[modnum][digit+1]='\0';
	if(find_answer((r*10+1)%modnum,digit+1,modnum))
	{
		succeed=1;
	}
	if(succeed)return 1;
	answer[modnum][digit]='0';
	if(find_answer((r*10)%modnum,digit+1,modnum))
	{
		succeed=1;
	}
	if(succeed)return 1;
	answer[modnum][digit]='\0';
	mem[r][digit]=1;
	return 0;
}

int main()
{
	int i,j,k;
	answer[1][0]='1';
	for(i=2;i<=200;i++)
	{
		succeed=0;
		answer[i][0]='1';
		for(j=0;j<=i+1;j++)
			for(k=1;k<=100;k++)
				mem[j][k]=0;
		find_answer(1,1,i);
	}
	while(cin>>i)
	{
		if(i==0)return 0;
		cout<<answer[i]<<endl;
	}
}