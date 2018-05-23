#include <stdio.h>  
struct InTree{  
    int l,u;  
    long long v;//使用long long 和输入输入的%lld来保证数据超过32位仍能正常运行  
    long long add;//add为延迟标记，标识它的子结点中的每个元素需要增加add  
};  
InTree tree[3*100000];  
//最多有2N-1个节点，最底层最多有N个节点，所以最多占用3N-2个位置。使用tree数组的1～3N-1位置。  
  
//A是输入的数据，i是当前节点在tree数组中的位置，l和u是上下界  
void BuildInTree(int *A,int i,int low, int upp){  
    tree[i].add = 0;  
    if(low==upp){  
        tree[i].l = tree[i].u = low;  
        tree[i].v = A[low];  
        return;  
    }  
    else{  
        tree[i].l = low;  
        tree[i].u = upp;  
        BuildInTree(A,2*i,low,(low+upp)/2);//左子树的位置为2*i  
        BuildInTree(A,2*i+1,(low+upp)/2+1,upp);//右子树的位置为2*i+1  
        tree[i].v = tree[2*i].v + tree[2*i+1].v;  
    }  
}  
  
//更新l到u区间的叶节点值加上v，tree[i]为当前节点，在这里采用延迟标记的方法  
void Update(int i,int low, int upp, long long v){  
    if(low <= tree[i].l && tree[i].u <= upp){  
        tree[i].v += (tree[i].u-tree[i].l+1)*v;//查询到本节点，更新数据  
        tree[i].add += v;//更新标记  
    }  
    else{  
    //更新tree[i]的左右的左右子树的标记  
        if(tree[i].add !=0){  
            //先把标记应用到子结点，再更新子结点的标记  
            tree[2*i].v += (tree[2*i].u-tree[2*i].l+1)* tree[i].add;  
            tree[2*i].add += tree[i].add;  
            tree[2*i+1].v += (tree[2*i+1].u-tree[2*i+1].l+1)* tree[i].add;  
            tree[2*i+1].add += tree[i].add;  
            tree[i].add = 0;//将本节点的标记置0  
        }  
  
        if(low<=(tree[i].l+tree[i].u)/2){  
            Update(2*i,low,upp,v);  
        }  
        if(upp>=(tree[i].l+tree[i].u)/2+1){  
            Update(2*i+1,low,upp,v);  
        }  
        tree[i].v = tree[2*i].v + tree[2*i+1].v;  
    }  
}  
  
//查询l到u之间的数据和，tree[i]为当前节点  
long long Query(int i,int low, int upp){  
    if(low <= tree[i].l && tree[i].u <= upp){  
        return tree[i].v;  
    }  
    else{  
    //更新tree[i]的左右的左右子树的标记  
        if(tree[i].add !=0){  
            //先把标记应用到子结点，再更新子结点的标记  
            tree[2*i].v += (tree[2*i].u-tree[2*i].l+1)* tree[i].add;  
            tree[2*i].add += tree[i].add;  
            tree[2*i+1].v += (tree[2*i+1].u-tree[2*i+1].l+1)* tree[i].add;  
            tree[2*i+1].add += tree[i].add;  
  
            tree[i].add = 0;//将本节点的标记置0  
        }  
        long long val = 0;  
        if(low<=(tree[i].l+tree[i].u)/2){  
            val += Query(2*i,low,upp);  
        }  
        if(upp>=(tree[i].l+tree[i].u)/2+1){  
            val += Query(2*i+1,low,upp);  
        }  
        return val;  
    }  
}  
int main(){  
    int N,Q;  
    scanf("%d %d", &N, &Q);  
    int *A = new int[N+1];//只使用1～N的区间  
    for(int i=1;i<=N;i++)scanf("%d", A+i);  
    BuildInTree(A,1,1,N);  
  
    char c[2];  
    int l,u;  
    long long add;  
  
    for(int i=0;i<Q;i++){  
        scanf("%1s",c);//读入一个非空白的字符，注意留空间给%s末尾的'\0'  
        if(c[0]=='Q'){  
            scanf("%d %d",&l,&u);  
            printf("%lld\n",Query(1,l,u));  
        }  
        else if(c[0]=='C'){  
            scanf("%d %d %lld",&l,&u,&add);  
            Update(1,l,u,add);  
        }  
    }  
    return 0;  
}  