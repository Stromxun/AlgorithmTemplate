### POJ 2566 [Bound Found](http://poj.org/problem?id=2566)  
##### 知识点： 双指针，前缀和

```cpp
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
int a[100005];
const int INF=0x7fffffff;
struct node{
    bool operator<(const node& a)const {
        return sum<a.sum;
    }
    int sum;
    int id;
}pre[100005];
int main(){
    int n,k;
    while(cin>>n>>k&&n){
        pre[0].id=pre[0].sum=0;//必须留index=0
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            pre[i].id=i;
            pre[i].sum=pre[i-1].sum+a[i];//使用前缀和
        }
        sort(pre,pre+1+n); //并将 index也加入排序 使得更区间之和具有单调性
        for(int i=1;i<=k;i++){
            int t;
            scanf("%d",&t);
            int Min=INF;//初始化
            int l=0,r=1;
            int ans,ansl,ansr;
            while(r<=n){
                int sub=pre[r].sum-pre[l].sum;//求之前的值
                while(abs(sub-t)<Min){//如果更优于之前的数据，更新
                    Min=abs(sub-t);
                    ansl=min(pre[l].id,pre[r].id)+1;//+1才是该区间的左边界
                    ansr=max(pre[l].id,pre[r].id);
                    ans=sub;
                }
                if(sub<t) r++; //绝对和的值比目标值小，便期望增加
                else if(sub>t) l++;//值比目标大，就期望减小
                else break;
                if(l==r) r++;//防止l>r
            }
            printf("%d %d %d\n",ans,ansl,ansr);
        }
    }
    return 0;
}
```
