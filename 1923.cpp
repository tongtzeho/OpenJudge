#include <iostream>
using namespace std;

char mem[102][5102][27]={0};
bool possi[102][5102]={0};

void f(const int x,const int y,const int z)
{
	if(x>100||(mem[x][y][z/8]&(1<<(z%8))))return;
	mem[x][y][z/8]|=1<<(z%8);
	possi[x][y]=1;
	f(x+1,y+x-z,z+1);
	f(x+1,y+x,1);
}

int main()
{
	int i,j,k=0;
	f(1,0,1);
	while(cin>>i>>j)
	{
		k++;
		if(i==0&&j==0)return 0;
		if(j<5100&&possi[i][j])
		{
			cout<<"Case "<<k<<": "<<i<<" lines with exactly "<<j<<" crossings can cut the plane into "<<i+j+1<<" pieces at most."<<endl;
		}
		else
		{
			cout<<"Case "<<k<<": "<<i<<" lines cannot make exactly "<<j<<" crossings."<<endl;
		}
	}
}