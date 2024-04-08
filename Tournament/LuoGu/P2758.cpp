#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXA = 2e3 + 10;
char a[MAXA], b[MAXA];
int dp[MAXA][MAXA];

int main()
{
    scanf("%s %s", a, b);
    int m = strlen(a), n = strlen(b);
    for(int i = m; i >= 0; i--) a[i] = a[i - 1];
    for(int i = n; i >= 0; i--) b[i] = b[i - 1];
    for(int i = 1; i <= m; i++) dp[i][0] = i;
    for(int i = 1; i <= n; i++) dp[0][i] = i;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            // int k = 1;
            // if(a[i] == b[j]) k = 0;
            if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(min(dp[i -1][j], dp[i][j-1])+1, dp[i-1][j-1] + 1);
        }
    }
    printf("%d", dp[m][n]);
    return 0;
}