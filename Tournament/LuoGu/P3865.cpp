#include<iostream>
#include<cmath>
using namespace std;

const int MAXA = 1e5 + 10;

int n, m;
int a[MAXA], dp_min[MAXA][22], dp_max[MAXA][22];
int LOG2[MAXA];

void st_init()
{
    LOG2[0] = -1;
    for(int i = 1; i <= n; i++) LOG2[i] = LOG2[i >> 1] + 1;
    for(int i = 1; i <= n; i++) dp_max[i][0] = a[i];
    int p = log2(n);
    for(int k = 1; k <= p; k++)
        for(int s = 1; s + (1 << k) <= n + 1; s++)
            dp_max[s][k] = max(dp_max[s][k - 1], dp_max[s + (1 << (k - 1))][k - 1]);
}

int st_query(int L, int R)
{
    int k = LOG2[R - L + 1];
    int x = max(dp_max[L][k], dp_max[R - (1 << k) + 1][k]);
    return x;
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    st_init();
    for(int i = 1; i <= m; i++){
        int l, r; scanf("%d %d", &l, &r);
        printf("%d\n", st_query(l, r));
    }
    return 0;
}