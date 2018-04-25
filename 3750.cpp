#include<iostream>
#include<cstring>
#include<string>
using namespace std;
struct data
{
	int id,hq,nm,at,hp,po,sp,dest,wk;
}
man[200];
int win=0,minute,posum[3][30]={0},casesum,cityhp[30],hq1hp,hq2hp,cityprior[30],hp0[6]={0},at0[6]={0},hq1born=0,hq2born=0,order1[5]={3,4,5,2,1},order2[5]={4,1,2,3,5};
int citysum,timelimit,citywinner[30]={0},n,rf[30],winlist1[30],winlist2[30],hq1hptemp,hq2hptemp,bonus1,bonus2,w1s,w2s;
string manname[6]={" ","dragon","ninja","iceman","lion","wolf"};
void outputtime();
void born();
void move();
void hqgethp();
void fight(int);
void atk(int,int,int,int);
void outputtime()
{
	int ho,mi;
	ho=minute/60;
	mi=minute%60;
	if(ho<10)cout<<"00"<<ho<<":";
	if(ho>=10)cout<<"0"<<ho<<":";
	if(mi==0)cout<<"00 ";
	else cout<<mi<<" ";
}
void born()
{
	int i;
	if(hp0[order1[hq1born%5]]<=hq1hp)
	{
		i=hq1born+hq2born+1;
		man[i].id=hq1born+1;
		man[i].hp=hp0[order1[hq1born%5]];
		man[i].hq=1;
		man[i].nm=order1[hq1born%5];
		man[i].po=0;
		man[i].sp=0;
		man[i].at=at0[order1[hq1born%5]];
		man[i].dest=1;
		man[i].wk=0;
		outputtime();
		cout<<"red "<<manname[order1[hq1born%5]]<<" "<<man[i].id<<" born\n";
		hq1born++;
		hq1hp-=man[i].hp;
	}
	if(hp0[order2[hq2born%5]]<=hq2hp)
	{
		i=hq1born+hq2born+1;
		man[i].id=hq2born+1;
		man[i].hp=hp0[order2[hq2born%5]];
		man[i].hq=2;
		man[i].nm=order2[hq2born%5];
		man[i].po=citysum+1;
		man[i].sp=0;
		man[i].at=at0[order2[hq2born%5]];
		man[i].dest=n;
		man[i].wk=0;
		outputtime();
		cout<<"blue "<<manname[order2[hq2born%5]]<<" "<<man[i].id<<" born\n";
		hq2born++;
		hq2hp-=man[i].hp;
	}
}
void move()
{
	int temp[200]={0},s=0,i,j,k;
	for(i=1;i<=hq1born+hq2born;i++)
		if(man[i].hp>0&&((man[i].hq==1&&man[i].po!=n+1)||(man[i].hq==2&&man[i].po!=0)))
		{
			s++;
			temp[s]=i;
		}
	for(i=1;i<=s;i++)
		for(j=i+1;j<=s;j++)
		{
			if(man[temp[i]].dest>man[temp[j]].dest||(man[temp[i]].dest==man[temp[j]].dest&&man[temp[i]].hq==2))
			{
				temp[i]^=temp[j];
				temp[j]^=temp[i];
				temp[i]^=temp[j];
			}
		}
	for(k=1;k<=s;k++)
	{
		i=temp[k];
		outputtime();
		if(man[i].hq==1)j=1;
		else j=-1;
		posum[man[i].hq][man[i].po]--;
		man[i].po+=j;
		man[i].dest+=j;
		posum[man[i].hq][man[i].po]++;
		man[i].wk++;
		if(man[i].wk%2==0&&man[i].nm==3)
		{
			man[i].hp-=9;
			if(man[i].hp<=0)man[i].hp=1;
			man[i].at+=20;
		}
		if(man[i].hq==1)
		{
			if(man[i].po<=n)
				cout<<"red "<<manname[man[i].nm]<<" "<<man[i].id<<" marched to city "<<man[i].po<<" with "<<man[i].hp<<" elements and force "<<man[i].at<<endl;
			if(man[i].po==n+1)
			{
				cout<<"red "<<manname[man[i].nm]<<" "<<man[i].id<<" reached blue headquarter with "<<man[i].hp<<" elements and force "<<man[i].at<<endl;
				if(posum[1][n+1]==2)
				{
					outputtime();
					cout<<"blue headquarter was taken\n";
					win=1;
				}
			}
		}
		if(man[i].hq==2)
		{
			if(man[i].po>0)
				cout<<"blue "<<manname[man[i].nm]<<" "<<man[i].id<<" marched to city "<<man[i].po<<" with "<<man[i].hp<<" elements and force "<<man[i].at<<endl;
			if(man[i].po==0)
			{
				cout<<"blue "<<manname[man[i].nm]<<" "<<man[i].id<<" reached red headquarter with "<<man[i].hp<<" elements and force "<<man[i].at<<endl;
		        if(posum[2][0]==2)
				{
					outputtime();
					cout<<"red headquarter was taken\n";
					win=1;
				}
			}
		}
	}
}
void hqgethp()
{
	int i,j,s=0,temp[200]={0};
	for(i=1;i<=hq1born+hq2born;i++)
	{
		if(man[i].hp>0&&(posum[1][man[i].po]+posum[2][man[i].po]==1)&&cityhp[man[i].po]>0)
		{
			s++;
			temp[s]=i;
		}
	}
	for(i=1;i<=s;i++)
		for(j=i+1;j<=s;j++)
		{
			if(man[temp[i]].po>man[temp[j]].po)
			{
				temp[i]^=temp[j];
				temp[j]^=temp[i];
				temp[i]^=temp[j];
			}
		}
	for(i=1;i<=s;i++)
	{
		if(man[temp[i]].hq==1)
		{
			outputtime();
			cout<<"red "<<manname[man[temp[i]].nm]<<" "<<man[temp[i]].id<<" earned "<<cityhp[man[temp[i]].po]<<" elements for his headquarter\n";
			hq1hp+=cityhp[man[temp[i]].po];
			cityhp[man[temp[i]].po]=0;
		}
		else
		{
			outputtime();
			cout<<"blue "<<manname[man[temp[i]].nm]<<" "<<man[temp[i]].id<<" earned "<<cityhp[man[temp[i]].po]<<" elements for his headquarter\n";
			hq2hp+=cityhp[man[temp[i]].po];
			cityhp[man[temp[i]].po]=0;
		}
	}
}
void fight(int pos)
{
	int i,m1,m2;
	for(i=1;i<=hq1born+hq2born;i++)
		if(man[i].po==pos)
		{
			if(man[i].hq==1)
			{
				m1=i;
			}
			else
			{
				m2=i;
			}
		}
	if(cityprior[pos]==1)
	{
		atk(m1,m2,1,pos);
		atk(m2,m1,0,pos);
	}
	else
	{
		atk(m2,m1,1,pos);
		atk(m1,m2,0,pos);
	}
}
void atk(int x,int y,int z,int pos)
{
	int at,aty,hpy;
	if(man[x].hp<=0)return;
	if(z==0&&man[x].nm==2)
	{
		if(man[y].nm==1)
		{
			outputtime();
			if(man[y].hq==1)cout<<"red ";
		    else cout<<"blue ";
		    cout<<manname[man[y].nm]<<" "<<man[y].id<<" yelled in city "<<pos<<endl;
		}
		citywinner[pos]=0;
		return;
	}
	if(z==1)at=man[x].at;
	if(z==0)at=man[x].at/2;
	aty=man[y].at;
	hpy=man[y].hp;
	outputtime();
	if(man[x].hq==1)cout<<"red ";
	else cout<<"blue ";
	if(z==1)
	{
		cout<<manname[man[x].nm]<<" "<<man[x].id<<" attacked ";
	    if(man[y].hq==1)cout<<"red ";
	    else cout<<"blue ";
	    cout<<manname[man[y].nm]<<" "<<man[y].id<<" in city "<<pos<<" with "<<man[x].hp<<" elements and force "<<man[x].at<<endl;
	}
	if(z==0)
	{
		cout<<manname[man[x].nm]<<" "<<man[x].id<<" fought back against ";
		if(man[y].hq==1)cout<<"red ";
	    else cout<<"blue ";
		cout<<manname[man[y].nm]<<" "<<man[y].id<<" in city "<<pos<<endl;
	}
	man[y].hp-=at;
	if(z==0&&man[y].hp>0)citywinner[pos]=0;
	if(z==0&&man[y].hp>0&&man[y].nm==1)
	{
		outputtime();
		if(man[y].hq==1)cout<<"red ";
	    else cout<<"blue ";
		cout<<manname[man[y].nm]<<" "<<man[y].id<<" yelled in city "<<pos<<endl;
	}
	if(man[y].hp<=0)
	{
		outputtime();
		if(man[y].hq==1)cout<<"red ";
		else cout<<"blue ";
		cout<<manname[man[y].nm]<<" "<<man[y].id<<" was killed in city "<<pos<<endl;
		if(man[x].nm==1&&z==1)
		{
			outputtime();
			if(man[x].hq==1)cout<<"red ";
		    else cout<<"blue ";
		    cout<<manname[man[x].nm]<<" "<<man[x].id<<" yelled in city "<<pos<<endl;
		}
		if(z==1&&man[x].nm==5)man[x].sp++;
		if(z==1&&man[x].nm==5&&man[x].sp%2==0)
		{
			man[x].hp*=2;
			man[x].at*=2;
		}
		if(man[y].nm==4)
		{
			man[x].hp+=hpy;
		}
		if(man[x].hq==1)
		{
			w1s++;
			winlist1[w1s]=x;
			bonus1+=cityhp[pos];
			if(cityhp[pos]>0)
			{
				outputtime();
				cout<<"red "<<manname[man[x].nm]<<" "<<man[x].id<<" earned "<<cityhp[pos]<<" elements for his headquarter\n";
			}
			cityhp[pos]=0;
		}
		if(man[x].hq==2)
		{
			w2s++;
			winlist2[w2s]=x;
			bonus2+=cityhp[pos];
			if(cityhp[pos]>0)
			{
				outputtime();
				cout<<"blue "<<manname[man[x].nm]<<" "<<man[x].id<<" earned "<<cityhp[pos]<<" elements for his headquarter\n";
			}
			cityhp[pos]=0;
		}
		if(man[x].hq==1)
		{
			if(citywinner[pos]<=0)citywinner[pos]=1;
			else citywinner[pos]++;
			if(citywinner[pos]==2)
			{
				if(cityprior[pos]==2||rf[pos]==0)
				{
					rf[pos]=1;
					outputtime();
					cout<<"red flag raised in city "<<pos<<endl;
				}
				cityprior[pos]=1;
			}
			posum[2][pos]=0;
		}
		if(man[x].hq==2)
		{
			if(citywinner[pos]>=0)citywinner[pos]=-1;
			else citywinner[pos]--;
			if(citywinner[pos]==-2)
			{
				if(cityprior[pos]==1||rf[pos]==0)
				{
					rf[pos]=1;
					outputtime();
					cout<<"blue flag raised in city "<<pos<<endl;
				}
				cityprior[pos]=2;
			}
			posum[1][pos]=0;
		}
	}
}
int main()
{
	int ca,i,j,k,l;
	cin>>casesum;
	for(ca=1;ca<=casesum;ca++)
	{
		cin>>hq1hp>>citysum>>timelimit;
		n=citysum;
		hq2hp=hq1hp;
		for(i=1;i<=5;i++)
			cin>>hp0[i];
		for(i=1;i<=5;i++)
			cin>>at0[i];
		for(i=0;i<=citysum+1;i++)
		{
			cityprior[i]=i%2==1?1:2;
			posum[1][i]=posum[2][i]=cityhp[i]=citywinner[i]=rf[i]=0;
		}
		win=hq1born=hq2born=minute=0;
		cout<<"Case:"<<ca<<endl;
		while(win==0&&minute<=timelimit)
		{
		    if(minute%60==0)born();
			if(minute%60==10)move();
			if(minute%60==20)
				for(i=1;i<=citysum;i++)
					cityhp[i]+=10;
			if(minute%60==30)hqgethp();
			if(minute%60==40)
			{
				w1s=w2s=bonus1=bonus2=0;
				hq1hptemp=hq1hp;
				hq2hptemp=hq2hp;
				for(i=1;i<=citysum;i++)
				{
					if(posum[1][i]+posum[2][i]==2)
					{
						fight(i);
					}
				}
				i=w1s;
				while(i>0&&hq1hp>8)
				{
					man[winlist1[i]].hp+=8;
					hq1hp-=8;
					i--;
				}
				hq1hp+=bonus1;
				i=0;
				while(i<w2s&&hq2hp>8)
				{
					i++;
					man[winlist2[i]].hp+=8;
					hq2hp-=8;
				}
				hq2hp+=bonus2;
			}
			if(minute%60==50)
			{
				outputtime();
				cout<<hq1hp<<" elements in red headquarter\n";
				outputtime();
				cout<<hq2hp<<" elements in blue headquarter\n";
			}
			minute+=10;
		}
	}
	return 0;
}