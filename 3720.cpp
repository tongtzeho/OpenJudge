#include<iostream>
#include<cstring>
#include<string>
using namespace std;
class TREE
{
	char ch;
	bool root;
	TREE *parent,*left,*right;
public:
	void input(const int up,const bool isroot,const char _ch,TREE *tree)
	{
		ch=_ch;
		root=isroot;
		parent=left=right=NULL;
		if(root)return;
		if(up==-1)
		{
			tree->left=this;
			parent=tree;
			return;
		}
		for(int i=0;i<=up;i++)
			tree=tree->parent;
		tree->right=this;
		parent=tree;
	}
	void DLR()
	{
		if(ch!='*')cout<<ch;
		if(left!=NULL) left->DLR();
		if(right!=NULL) right->DLR();
	}
	void LDR()
	{
		if(left!=NULL) left->LDR();
		if(ch!='*')cout<<ch;
		if(right!=NULL) right->LDR();
	}
	void LRD()
	{
		if(left!=NULL) left->LRD();
		if(right!=NULL) right->LRD();
		if(ch!='*')cout<<ch;
	}
}tree[300];
int main()
{
	int n,i,j,l;
	bool first;
	string str;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		j=first=0;
		while(cin>>str)
		{
			if(str=="0")break;
			if(!first)
			{
				first=1;
				tree[0].input(NULL,1,str[0],NULL);
			}
			else
			{
				tree[j].input(l-str.length(),0,str[str.length()-1],tree+j-1);
			}
			l=str.length();
			j++;
		}
		tree[0].DLR();
		cout<<endl;
		tree[0].LRD();
		cout<<endl;
		tree[0].LDR();
		cout<<endl<<endl;
	}
	return 0;
}
