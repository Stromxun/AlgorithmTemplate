### HUD 3999 [The order of a Tree](https://acm.hdu.edu.cn/showproblem.php?pid=3999)  
##### 知识点： 树、二叉搜索树

```cpp
#include<iostream>
#include<cstdio>

using namespace std;
int n;
struct node{
    node* l, *r;
    int val;
    node(int val=0,node* l=NULL,node* r=NULL):val(val),l(l),r(r){}
};

int k=0;
node* buildtree(node* tree,int val){
    if(tree==NULL) tree=new node(val);
    else if(tree->val>=val) tree->l=buildtree(tree->l,val);
    else tree->r=buildtree(tree->r,val);
    return tree;
}

void printpost(node* tree){
    printf("%d%c",tree->val,(++k)!=n?' ':'\n');
    if(tree->l!=NULL) printpost(tree->l);
    if(tree->r!=NULL) printpost(tree->r);
}

int main(){
    while(~scanf("%d",&n)){
        node* tree=NULL;
        int temp;
        k=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&temp);//输入数据
            tree=buildtree(tree,temp);
        }
        printpost(tree);
        printf("\n");
    }
    return 0;
}
```
