#include<iostream>
#include<algorithm>
using namespace std;
const int MAXA = 1e3 + 10;
int n;
int a[MAXA][MAXA], dp[MAXA][MAXA];
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
        }
    }
    int mx = 0;
    for(int i = 1; i <= n; i++){
        mx = max(dp[n][i], mx);
    }
    printf("%d", mx);
}