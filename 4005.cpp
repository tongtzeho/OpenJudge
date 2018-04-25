#include<stdio.h>
#include<algorithm>
using namespace std;

class CARDLIST;
class GAME;

inline int chocolate(const int x,const int y)
{
	if(x>y)return 3;
	else if(x==y)return 2;
	else return 1;
}

inline int max(const int x,const int y)
{
	if(x>y)return x;
	else return y;
}

class CARDLIST
{
	friend class GAME;
	int n,*card;
	void init(const int n_)
	{
		n=n_;
		card=new int[n];
		for(int i=0;i<n;i++)
			scanf("%d",card+i);
		sort(card,card+n);
	}
	int beat(const CARDLIST &c)
	{
		int i,j,mem[2][1001]={0};
		for(i=n-1;i>=0;i--)
			for(j=0;j<=i;j++)
				mem[i%2][j]=max(mem[(i+1)%2][j]+chocolate(card[i],c.card[n+j-i-1]),mem[(i+1)%2][j+1]+chocolate(card[i],c.card[j]));
		return mem[0][0];
	}
};

class GAME
{
	int playersum;
	CARDLIST C,S;
public:
	GAME(const int n)
	{
		playersum=n;
		C.init(playersum);
		S.init(playersum);
	}
	void output()
	{
		int temp1=S.beat(C),temp2=C.beat(S);
		printf("%d %d\n",temp1,4*playersum-temp2);
	}
};

int main()
{
	int n;
	while(scanf("%d",&n))
	{
		if(n==0)return 0;
		GAME game(n);
		game.output();
	}
}