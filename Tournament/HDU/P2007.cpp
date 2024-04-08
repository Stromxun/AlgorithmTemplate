#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXA = 1e2 + 10;
int a[MAXA][MAXA];
int dp[2][MAXA];
int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF && n && m){
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                scanf("%d", &a[i][j]);
            }
        }
        int old = 0, now = 1;
        for(int i = 1; i <= n; i++){
            swap(old, now);
            for(int j = 1; j <= m; j++){
                for(int k = 1; k <= m; k++){
                    if(k <= j){
                        dp[now][j] = max(dp[now][j], dp[old][j - k] + a[i][k]);
                    }
                }
            }
        }
        printf("%d\n", dp[now][m]);
    }
    return 0;
}