#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXA = 1e2 + 10;
int c[MAXA][MAXA], dp[MAXA], w[MAXA][MAXA];

int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m) && n && m){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                scanf("%d", &w[i][j]);
                c[i][j] = j;
            }
        }
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++){
            for(int j = m; j > 0; j--){
                for(int k = 1; k <= m; k++){
                    if(j >= c[i][k]){
                        dp[j] = max(dp[j], dp[j - k] + w[i][k]);
                    }
                }
            }
        }
        printf("%d\n", dp[m]);
    }
}