#include<stdio.h>
#include<algorithm>
using namespace std;

class PLAYER;
class COMPETITION;

class PLAYER
{
public:
	int id,atk,score;
};

bool cmp(const PLAYER &p1,const PLAYER &p2)
{
	if(p1.score!=p2.score)return p1.score>p2.score;
	else return p1.id<p2.id;
}

class COMPETITION
{
	int playersum;
	PLAYER *player;
public:
	COMPETITION(const int n)
	{
		playersum=2*n;
		player=new PLAYER[playersum];
		int i,temp;
		for(i=0;i<playersum;i++)
		{
			scanf("%d",&temp);
			player[i].id=i+1;
			player[i].score=temp;
		}
		for(i=0;i<playersum;i++)
		{
			scanf("%d",&temp);
			player[i].atk=temp;
		}
		sort(player,player+playersum,cmp);
	}
	~COMPETITION()
	{
		delete []player;
	}
	void play(const int round)
	{
		int i,j,win,lose;
		PLAYER *winner=new PLAYER[playersum/2],*loser=new PLAYER[playersum/2];
		for(i=1;i<=round;i++)
		{
			for(j=0;j<playersum;j+=2)
			{
				if(player[j].atk<player[j+1].atk)
				{
					win=j+1;
					lose=j;
				}
				else 
				{
					win=j;
					lose=j+1;
				}
				player[win].score++;
				winner[j/2]=player[win];
				loser[j/2]=player[lose];
			}
			win=lose=0;
			for(j=0;j<playersum;j++)
			{
				if(win<playersum/2&&cmp(winner[win],loser[lose]))
				{
					player[j]=winner[win];
					win++;
				}
				else
				{
					player[j]=loser[lose];
					lose++;
				}
			}
		}
	}
	void output(const int rank)
	{
		printf("%d",player[rank-1].id);
	}
};

int main()
{
	int n,r,q;
	scanf("%d%d%d",&n,&r,&q);
	COMPETITION competition(n);
	competition.play(r);
	competition.output(q);
	return 0;
}