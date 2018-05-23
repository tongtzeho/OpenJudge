#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
#include<list>
using namespace std;
bool isorder(const string str)
{
	return str=="copy"||str=="add"||str=="find"||str=="rfind"||str=="insert"||str=="reset"||str=="print"||str=="printall";
}
bool isnumber(const string str)
{
	if(str.length()>5)return false;
	for(int i=0;i<str.length();i++)
		if(str[i]<'0'||str[i]>'9')return false;
	return true;
}
int stringtoint(const string str)
{
	stringstream ss;
	ss<<str;
	int n;
	ss>>n;
	return n;
}
string inttostring(const int n)
{
	stringstream ss;
	ss<<n;
	string str;
	ss>>str;
	return str;
}
int main()
{
	list<string> lst;
	list<string>::iterator iter,iter1,iter2,iter3;
	string *str,order;
	int n,i,a,b,c;
	char ch;
	cin>>n;
	str=new string[n];
	for(i=0;i<n;i++)
		cin>>str[i];
	cin.get();
	while(1)
	{
		while(1)
		{
			cin>>order;
			if(order=="over")return 0;
			lst.push_back(order);
			cin.get(ch);
			if(ch=='\n')break;
		}
		while(!lst.empty())
		{
			iter=lst.end();
			iter--;
			for( ; ;iter--)
				if(isorder(*iter))break;
			iter1=iter;
			iter1++;
			iter2=iter1;
			iter2++;
			iter3=iter2;
			iter3++;
			if(*iter=="copy")
			{
				a=stringtoint(*iter1);
				b=stringtoint(*iter2);
				c=stringtoint(*iter3);
				*iter=str[a-1].substr(b,c);
				lst.erase(iter1,++iter3);
				if(lst.size()==1)lst.erase(iter);
			}
			else if(*iter=="add")
			{
				if(isnumber(*iter1)&&isnumber(*iter2))
				{
					a=stringtoint(*iter1);
					b=stringtoint(*iter2);
					c=a+b;
					*iter=inttostring(c);
				}
				else *iter=*iter1+*iter2;
				lst.erase(iter1,++iter2);
				if(lst.size()==1)lst.erase(iter);
			}
			else if(*iter=="find"||*iter=="rfind")
			{
				a=stringtoint(*iter2);
				if(*iter=="find")b=str[a-1].find(*iter1);
				else b=str[a-1].rfind(*iter1);
				if(b==string::npos)b=(*iter1).length();
				*iter=inttostring(b);
				lst.erase(iter1,++iter2);
				if(lst.size()==1)lst.erase(iter);
			}
			else if(*iter=="insert")
			{
				b=stringtoint(*iter2);
				c=stringtoint(*iter3);
				str[b-1].insert(c,*iter1);
				lst.erase(iter,++iter3);
			}
			else if(*iter=="reset")
			{
				b=stringtoint(*iter2);
				str[b-1]=*iter1;
				lst.erase(iter,++iter2);
			}
			else if(*iter=="print")
			{
				a=stringtoint(*iter1);
				cout<<str[a-1]<<endl;
				lst.erase(iter,++iter1);
			}
			else
			{
				for(i=0;i<n;i++)
					cout<<str[i]<<endl;
				lst.erase(iter);
			}
		}
	}
}