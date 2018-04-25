#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	string input[20]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
	string output[20]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
	string st;
	int dayin,monthin,yearin,num,dayout,monthout,yearout,i,j,k,t,n;
	cin>>n;
	cout<<n<<endl;
	for(i=1;i<=n;i++)
	{
		cin>>dayin;
		cin.get();
		cin>>st;
		monthin=0;
		for(j=0;j<20;j++)
			if(st==input[j])monthin=j;
		cin>>yearin;
		num=yearin*365+monthin*20+dayin+1;
		yearout=(num-1)/260;
		monthout=num%20;
		if(monthout==0)monthout=20;
		dayout=num%13;
		if(dayout==0)dayout=13;
		cout<<dayout<<' '<<output[monthout-1]<<' '<<yearout<<endl;
	}
	return 0;
}