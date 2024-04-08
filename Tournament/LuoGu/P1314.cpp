#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
const int MAXA = 2e5 + 10;

int w[MAXA], v[MAXA], l[MAXA], r[MAXA];
long long sum_v[MAXA], sum_n[MAXA];
int n, m;
long long Y, s, temp;

bool check(int W)
{
    Y = 0, temp = 0;
    memset(sum_n, 0, sizeof(sum_n));
    memset(sum_v, 0, sizeof(sum_v));
    for(int i = 1; i <= n; i ++){
        if(w[i] >= W) sum_n[i] = sum_n[i - 1] + 1, sum_v[i] = sum_v[i - 1] + v[i];
        else sum_n[i] = sum_n[i - 1], sum_v[i] = sum_v[i - 1];
    }
    for(int i = 1; i <= m; i++)
        Y += (sum_n[r[i]] - sum_n[l[i] - 1]) * (sum_v[r[i]] - sum_v[l[i] - 1]);
    temp = llabs(Y - s);
    if(Y > s) return true;
    else return false;
}

int main()
{
    int mina = 1e7, maxa = 0;
    scanf("%d %d %lld", &n, &m, &s);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &w[i], &v[i]);
        maxa = max(maxa, w[i]);
        mina = min(mina, w[i]);
    }
    for(int i = 1; i <= m; i++) scanf("%d %d", &l[i], &r[i]);
    long long ans=0x3f3f3f3f3f3f3f3f;
    int right = maxa + 2, left = mina - 1;
    while(left <= right){
        int mid = (right + left) >> 1;
        if(check(mid)) left = mid + 1;
        else right = mid - 1;
        if(temp < ans) ans = temp;
    }
    printf("%lld", ans);
    return 0;
}