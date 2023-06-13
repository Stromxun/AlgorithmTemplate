### HDU 4585 [Shaolin](https://acm.hdu.edu.cn/showproblem.php?pid=4585)
##### 知识点： Threap数、map 

<br>

map解法
```cpp
#include<iostream>
#include<map>

using namespace std;
map<int,int> mp;

int main(){
    int n;
    while(scanf("%d",&n),n){
        mp.clear();
        mp[1000000000]=1;  //方丈id = 1,等级 1000000000
        while(n--){        //此处方丈是作为哨兵的存在
            int id,g;
            scanf("%d %d",&id,&g); //新和尚 id ,等级 g
            mp[g]=id;          //新和尚进好队
            int ans;
            map<int,int>::iterator it=mp.find(g);//找到自身的位置
            if(it==mp.begin()){
                ans=(++it)->second;
            }else{
                map<int,int>::iterator it2=it;
                it2--;it++;
                if(g-it2->first<=it->first-g) //it指向的是战斗力比较小的和尚
                    ans=it2->second;          //it2指向的是战斗力较高的和尚
                else 
                    ans=it->second;
            }
            printf("%d %d\n",id,ans);
        }
    }
    return 0;
}
```

<br>

Thread(名次树)解法
```cpp
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>
using namespace std;
#define ll long long
const int ding=1e5+5;
struct Treap{
    int l,r;
    int val,dat;//节点关键码，权值 
    int cnt,size;//副本数，子树大小 
}a[ding];
int n,root,tot=0;
const int INF=0x3f3f3f3f;
int New(int id,int val){
    a[++tot].val=val;
    a[tot].dat=id;
    a[tot].cnt=a[tot].size=1;
    return tot;
}
void update(int p){
    a[p].size=a[a[p].l].size+a[a[p].r].size+a[p].cnt;
}
int getrankbyval(int p,int val){
    if(p==0){
        return 0;
    } 
    if(val==a[p].val)return a[a[p].l].size+1;
    if(val<a[p].val)return getrankbyval(a[p].l,val);
    return getrankbyval(a[p].r,val)+a[a[p].l].size+a[p].cnt;
}
int getvalbyrank(int p,int rank){
    if(p==0){
        return INF;
    }
    //如果 左子树的数量大于rank那个排名rank的节点一定在左子树里面 
    if(a[a[p].l].size>=rank)return getvalbyrank(a[p].l,rank);
    //如果恰好大于等于，说明就是这个点 
    if(a[a[p].l].size+a[p].cnt>=rank)return a[p].val;
    //否则就在右子树里面，要判断右子树有没有这么多节点，所以是rank-a[a[p].l].size-a[p].cnt; 
    return getvalbyrank(a[p].r,rank-a[a[p].l].size-a[p].cnt);
}
void zig(int &p){
    int q=a[p].l;
    a[p].l=a[q].r,a[q].r=p,p=q;
    update(a[p].r),update(p);
}
void zag(int &p){
    int q=a[p].r;
    a[p].r=a[q].l,a[q].l=p,p=q;
    update(a[p].l),update(p);
}
int getpre(int val){
    int ans=1;
    int p=root;
    while(p){
        if(val==a[p].val){
            if(a[p].l>0){
                p=a[p].l;
                while(a[p].r>0)p=a[p].r;
                ans=p;
            }
            break;
        }
        if(a[p].val<val&&a[p].val>a[ans].val)ans=p;
        p=val<a[p].val?a[p].l:a[p].r;
    }
    return ans;
}
int getnext(int val){
    int ans=2;
    int p=root;
    while(p){
        if(val==a[p].val){
            if(a[p].r>0){
                p=a[p].r;
                while(a[p].l>0)p=a[p].l;
                ans=p;
            }
            break;
        }
        if(a[p].val>val&&a[p].val<a[ans].val)ans=p;
        p=val<a[p].val?a[p].l:a[p].r;
    }
    return ans;
}
void remove(int &p,int val){
    if(p==0){
        return ;
    }
    if(val==a[p].val){
        //有重复节点数，减少数量 
        if(a[p].cnt>1){
            a[p].cnt--;
            update(p);
            return;
        }
        if(a[p].l||a[p].r){
            if(a[p].r==0||a[a[p].l].dat>a[a[p].r].dat){
                zig(p),remove(a[p].r,val);
            }
            else{
                zag(p),remove(a[p].l,val);
            }
            update(p);
        }
        else p=0;
        return;
    }
    val<a[p].val?remove(a[p].l,val):remove(a[p].r,val);
    update(p);
}
 
void insert(int &p,int id,int val){
    //如果是空树，重新插入节点 
    if(p==0){
        p=New(id,val);
        return;
    }
    //树中已经有了该节点 
    if(val==a[p].val){
        a[p].cnt++,update(p);
        return;
    } 
    //插入左子树 
    if(val<a[p].val){
        insert(a[p].l,id,val);
        //旋转 
        if(a[p].dat<a[a[p].l].dat)zig(p);
    }
    //插入右子树 
    else {
        insert(a[p].r,id,val);
        if(a[p].dat<a[a[p].r].dat)zag(p); 
    }
    update(p); 
}
void build(){
    New(0,-INF),New(0,INF);
    
    
    root=1;
    a[1].r=2;
    update(root); 
}
 
int main()
{
    while(~scanf("%d",&n)&&n){
        memset(a,0,sizeof(a));
        tot=0;
        build();
        insert(root,1,1000000000);
        while(n--){
            int id,val;
            scanf("%d %d",&id,&val);
            int pre=getpre(val);
            int next=getnext(val);
            if(val-a[pre].val<=a[next].val-val){
                printf("%d %d\n",id,a[pre].dat);
            }
            else{
                printf("%d %d\n",id,a[next].dat);
            }
            insert(root,id,val);
        }
    }
 return 0;
}
```
