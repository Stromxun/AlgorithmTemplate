### Treap树模板

Treap树是集合了平衡树和堆的性质，子树优先级最高的节点做根节点,同时具有了二叉树的平衡性，优先级由` rand() `函数来随机生成
从数学期望上讲是能够平衡的

Treap通常是抽象为名次树模型

```cpp
#include<bits/stdc++.h>
const int M = 1e6 + 10;
using namespace std;
int cnt = 0;

struct Node {
	int ls, rs; //左右子节点
	int key, pri;  //键值、优先级
	int size; //当前节点为根时
}t[M];//以顺序存储结构来存储

void newNode(int x){  //初始化一个新节点
    cnt++;
    t[cnt].size=1;
    t[cnt].ls=t[cnt].rs=0;
    t[cnt].key=x;
    t[cnt].pri=rand();//随机优先级
}

void Update(int u){
    t[u].size=t[t[u].ls].size + t[t[u].rs].size + 1;//左右子树的节点总数 加 上根节点
}

void rotate(int& o,int d){
    int k;
    if(d==1){//左旋
        k=t[o].rs;
        t[o].rs=t[k].ls;
        t[k].ls=o;
    }else{//右旋
        k=t[o].ls;
        t[o].ls=t[k].rs;
        t[k].rs=o;
    }
    t[k].size=t[o].size; //总节点数不变
    Update(o);  //更新o节点的size
    o=k; //更新根节点
}

void Insert(int &u,int x){
    if(u==0){
        newNode(x);u=cnt;return;//找到符合的位置
    }
    t[u].size++;//预先处理size+1(将在此子树插入的新节点)
    if(x>=t[u].key) Insert(t[u].rs,x);//比该子树根节点的键值大，右移
    else Insert(t[u].ls,x); //流向左子树
    //开始平衡
    if(t[u].ls!=0&&t[u].pri>t[t[u].ls].pri) rotate(u,0);   //在线维护树堆的平衡态,
    if(t[u].rs!=0&&t[u].pri>t[t[u].rs].pri) rotate(u,1);   //如果右子树根节点的优先级小于根节点的优先级，左旋
    Update(u);//更新数据
}

void Del(int &u,int x){
    t[u].size--;//该子树节点数量-1
    if(t[u].key==x){//找到该节点，开始进行删除操作
        if(t[u].ls==0&&t[u].rs==0){u=0;return;}//变换到叶子节点，直接删除
        if(t[u].ls==0||t[u].rs==0){u=t[u].ls+t[u].rs;return;}//如果该子树根节点只有一个子节点，直接让其顶替其位置，以达到删除的效果
        if(t[t[u].ls].pri<t[t[u].rs].pri){//该条件顺便维护一下
            rotate(u,0);Del(t[u].rs,x);return;//右旋
        }else{
            rotate(u,1);Del(t[u].ls,x);return;//左旋
        }
    }
    if(t[u].key>=x) Del(t[u].ls,x);
    else            Del(t[u].rs,x);
    Update(u);
}

int Rank(int u,int x){
    if(u==0) return 0;
    if(x>t[u].key) return t[t[u].ls].size+1+Rank(t[u].rs,x);
    return Rank(t[u].ls,x);
}

int kth(int u,int k){//利用了二叉搜索树的性质和预先处理的size成员
    if(k==t[t[u].ls].size+1) return t[u].key;
    if(k>t[t[u].ls].size+1) return kth(t[u].rs,k-t[t[u].ls].size-1);//右子树
    if(k<=t[t[u].ls].size) return kth(t[u].ls,k);//左子树
}

int Precursor(int u,int x){//寻找直接前驱(前驱定义为小于 x，且最大的数)
    if(u==0) return 0;
    if(t[u].key>=x) return Precursor(t[u].ls,x);//寻找以key==x的根节点的最右子节点
    int tmp=Precursor(t[u].rs,x);
    if(tmp==0) return t[u].key;
    return tmp;
}

int Successor(int u,int x){//寻找直接后继(后继定义为大于 x，且最小的数)
    if(u==0) return 0;
    if(t[u].key<=x) return Successor(t[u].rs,x);//寻找以key==x的根节点的最左子节点
    int tmp=Successor(t[u].ls,x);
    if(tmp==0) return t[u].key;
    return tmp;
}
int main() {//Treap的随机性导致此算法可能含有运气成分
    srand(time(NULL));
    int root=0;
    int n;cin>>n;
    while(n--){
        int opt,x;
        cin>>opt>>x;
        switch(opt){
            case 1:Insert(root,x); break;
            case 2:Del(root,x); break;
            case 3:printf("%d\n",Rank(root,x)+1); break;
            case 4:printf("%d\n",kth(root,x)); break;
            case 5:printf("%d\n",Precursor(root,x)); break;
            case 6:printf("%d\n",Successor(root,x)); break;
        }
    }
	return 0;
}
```
