#include<iostream>
using namespace std;
const int MAXA = 1e7 + 10;
int w[MAXA], v[MAXA];
long long f[MAXA];
int main()
{
    int t, m; scanf("%d %d", &t, &m);
    for(int i = 1; i <= m; i++){
        scanf("%d %d", &v[i], &w[i]);
    }
    for(int i = 1; i <= m; i++){
        for(int j = v[i]; j <= t; j++){
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    printf("%lld", f[t]);
    return 0;
}