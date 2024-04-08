#include<iostream>
#include<algorithm>
using namespace std;
const int MAXA =  1e5 + 5e4 + 5;

struct Node{
    int head;
    int tail;
    int val;
} a[MAXA];

int dp[MAXA];
int n;

inline bool cmp(Node x, Node y)
{
    return x.tail < y.tail;
}

inline int lower_bound(int l, int r, int key)
{
    int ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(a[mid].tail < key) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    for(register int i = 1; i <= n; i++){
        scanf("%d %d", &a[i].head, &a[i].tail);
        a[i].val = a[i].tail - a[i].head + 1;
    }
    sort(a + 1, a + n + 1, cmp);
    for(register int i = 1; i <= n; i++){
        dp[i] = max(dp[i - 1], dp[lower_bound(1, i - 1, a[i].head)] + a[i].val);
    }
    printf("%d", dp[n]);
    return 0;
}