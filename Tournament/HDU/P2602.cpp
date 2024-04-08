#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXA = 1e3 + 10;
int dp[MAXA][MAXA], a[MAXA], b[MAXA];

int solve(int i, int j)
{
    if(dp[i][j] != 0) return dp[i][j];
    if(i == 0) return 0;
    int ans;
    if(b[i] > j) ans = solve(i - 1, j);
    else ans =  max(solve(i - 1, j), solve(i - 1, j - b[i]) + a[i]);
    return dp[i][j] = ans;
}

int main()
{
    int t; scanf("%d", &t);
    while(t--){
        int n, v; scanf("%d %d", &n, &v);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
        memset(dp, 0, sizeof(dp));
        printf("%d\n", solve(n, v));
    }
}