#include<iostream>
#include<cmath>
using namespace std;

const int MAXA = 1e5 + 10;
int n, m;
int a[MAXA], LOG2[MAXA];
int dp_min[MAXA][22];

void st_init()
{
    LOG2[0] = -1;
    for(int i = 1; i <= n; i++) LOG2[i] = LOG2[i >> 1] + 1;
    for(int i = 1; i <= n; i++) dp_min[i][0] = a[i];
    int p = log2(n);
    for(int k = 1; k <= p; k++){
        for(int s = 1; s + (1 << k) <= n + 1; s++){
            dp_min[s][k] = min(dp_min[s][k - 1], dp_min[s + (1 << (k - 1))][k - 1]);
        }
    }
}

int st_query(int l, int r)
{
    int k = LOG2[r - l + 1];
    int x = min(dp_min[l][k], dp_min[r - (1 << k) + 1][k]);
    return x;
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    st_init();
    for(int i = 1; i <= n - m + 1; i++)
        printf("%d\n", st_query(i, i + m - 1));
    return 0;
}