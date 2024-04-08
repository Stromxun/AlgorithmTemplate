#include<iostream>
#include<string.h>
using namespace std;

const int MAXA = 5e4 + 10;

long long a[MAXA];
int l[7], r[7];

int main()
{
    int n; scanf("%d", &n);
    memset(l, -1, sizeof(l)), memset(r, -1, sizeof(r));
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];
    }
    l[0] = 0;
    for(int i = 1; i <= n; i++){
        int t = a[i] % 7;
        if(l[t] == -1) l[t] = i;
        else r[t] = i;
    }
    int ans = r[0];
    for(int i = 1; i < 7; i++){
        if(l[i] == -1 || r[i] == -1) continue;
        ans = max(ans, r[i] - l[i]);
    }
    printf("%d", ans);
    return 0;
}