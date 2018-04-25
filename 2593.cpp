#include<iostream>
using namespace std;

const int MIN_INT=-2147481648;

class DATA
{
public:
	int n,suml,sumr,pminl,pminr,maxnuml,maxnumr,resultl,resultr;
	void init(const int N)
	{
		n=suml=sumr=pminl=0;
		pminr=N+1;
		maxnuml=maxnumr=resultl=resultr=MIN_INT;
	}
	void output(int i)
	{
		cout<<i<<" "<<n<<" "<<suml<<" "<<sumr<<" "<<pminl<<" "<<pminr<<" "<<maxnuml<<" "<<maxnumr<<" "<<resultl<<" "<<resultr<<endl;
	}
}data[100002];

inline int maxnum(const int x,const int y)
{
	if(x>y)return x;
	else return y;
}

int main()
{
	int N,i,result,temp,p1,p2;
	while(cin>>N&&N!=0)
	{
		data[0].init(N);
		for(i=1;i<=N;i++)
		{
			data[i].init(N);
			cin>>data[i].n;
			data[i].suml=data[i].n+data[i-1].suml;
			p1=data[i-1].pminl;
			if(data[i].suml<data[p1].suml)data[i].pminl=i;
			else data[i].pminl=p1;
			if(data[i].n>data[i-1].maxnuml)data[i].maxnuml=data[i].n;
			else data[i].maxnuml=data[i-1].maxnuml;
			p2=data[i].pminl;
			temp=data[i].suml-data[p2].suml;
			if(i==p2&&temp==0)temp=data[i].maxnuml;
			data[i].resultl=maxnum(data[i-1].resultl,temp);
		}
		data[N+1].init(N);
		result=MIN_INT;
		for(i=N;i>1;i--)
		{
			data[i].sumr=data[i].n+data[i+1].sumr;
			p1=data[i+1].pminr;
			if(data[i].sumr<data[p1].sumr)data[i].pminr=i;
			else data[i].pminr=p1;
			if(data[i].n>data[i+1].maxnumr)data[i].maxnumr=data[i].n;
			else data[i].maxnumr=data[i+1].maxnumr;
			p2=data[i].pminr;
			temp=data[i].sumr-data[p2].sumr;
			if(i==p2&&temp==0)temp=data[i].maxnumr;
			data[i].resultr=maxnum(data[i+1].resultr,temp);
			if(data[i-1].resultl+data[i].resultr>result)result=data[i-1].resultl+data[i].resultr;
		}
	//	for(i=1;i<=N;i++)
	//		data[i].output(i);
		cout<<result<<endl;
	}
	return 0;
}