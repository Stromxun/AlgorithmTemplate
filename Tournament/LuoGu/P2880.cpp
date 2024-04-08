#include<iostream>
#include<cmath>
using namespace std;

const int MAXA = 5e4 + 10;

int n, q;
int a[MAXA], dp_max[MAXA][22], dp_min[MAXA][22];
int LOG2[MAXA];

void st_init()
{
    LOG2[0] = -1;
    for(int i = 1; i <= n; i++) LOG2[i] = LOG2[i >> 1] + 1;
    for(int i = 1; i <= n; i++){
        dp_min[i][0] = a[i];
        dp_max[i][0] = a[i];
    }
    int p = log2(n);
    for(int k = 1; k <= p; k++){
        for(int s = 1; s + (1 << k) <= n + 1; s++){
            dp_max[s][k] = max(dp_max[s][k - 1], dp_max[s + (1 << (k - 1))][k - 1]);
            dp_min[s][k] = min(dp_min[s][k - 1], dp_min[s + (1 << (k - 1))][k - 1]);
        }
    }
}

int st_query(int L, int R)
{
    int k = LOG2[R - L + 1];
    int x = max(dp_max[L][k], dp_max[R - (1 << k) + 1][k]);
    int y = min(dp_min[L][k], dp_min[R - (1 << k) + 1][k]);
    return x - y;

}

int main()
{
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    st_init();
    for(int i = 1; i <= q; i++){
        int L, R; scanf("%d %d", &L, &R);
        printf("%d\n", st_query(L, R));
    }
    return 0;
}