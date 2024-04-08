### 洛谷 P3045 [P3045 [USACO12FEB] Cow Coupons G](https://www.luogu.com.cn/problem/P3045)
##### 知识点： 堆

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define maxn 50010
using namespace std;
typedef long long ll;

struct P{
    int p,c;
}a[maxn];
int n,k;
ll m;
bool cmp(P x,P y)
{
    return x.c<y.c;
}
priority_queue<int,vector<int>,greater<int> >q1;//小根堆
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q2,q3; //小根堆
bool book[maxn];
int main()
{
    scanf("%d %d %d",&n,&k,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&a[i].p,&a[i].c);
    }
    sort(a+1,a+n+1,cmp);
    ll now=0;
    for(int i=1;i<=k;i++)
    {
        now+=a[i].c;
        if(now>m)
        {
            printf("%d\n",i-1);//需要的钱超了，相当于买不了那么多
            return 0;
        }
        q1.push(a[i].p-a[i].c);
    }
    if(k==n)//当前面的优惠券都用完了，还剩了钱，并且卷的数量等于牛的数量
    {       //不正是所有牛都买了吗
        printf("%d\n",n);
        return 0;
    }
    for(int i=k+1;i<=n;i++)//维护剩下的牛的数值
    {
        q2.push(make_pair(a[i].c,i));//折扣价
        q3.push(make_pair(a[i].p,i));//原价
    }
    int ans=k;//买完优惠后的k头牛
    for(int i=k+1;i<=n;i++)//还有钱，继续买
    {
        while(book[q2.top().second])  q2.pop();//如果这头牛已经被买了
        while(book[q3.top().second])  q3.pop();//防碰撞
        int p1=q2.top().second;
        int p2=q3.top().second;
        int tmp1=q2.top().first+q1.top();
        int tmp2=q3.top().first;
        if(tmp1<tmp2)//如果折扣价最低的牛+折扣所折金额 比 当前原价最便宜的牛 便宜
        {
            now+=tmp1;
            q1.pop();q2.pop();//替换掉 使用优惠券且最没有性价比的 牛
            q1.push(a[p1].p-a[p1].c);//新的差价入堆
            book[p1]=true;//我买了！
        }
        else{//替换后的最优价格还没我原价好,不换了！
            now+=tmp2;
            q3.pop();
            book[p2]=true;//我买了！
        }
        ans++;
        if(now>m)//金额超了 并且当前 价格最低的牛都吃不下了
        {
            printf("%d\n",ans-1);
            return 0;
        }
    }
    printf("%d\n",n);//全买完了
    return 0;
}
```
