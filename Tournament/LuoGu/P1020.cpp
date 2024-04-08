#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXA = 1e5 + 10;
int a[MAXA], dp[MAXA], f[MAXA];
int main()
{
    int n = 0;
    while(scanf("%d", &a[++n]) != EOF){
        dp[n] = 1;
    }
    int ans = 0, res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(a[j] < a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }else if(i != j && a[j] >= a[i]){
                f[i] = max(f[i], f[j] + 1);
            }
        }
        ans = max(ans, f[i]);
        res = max(res, dp[i]);
    }
    printf("%d\n%d", ans, res);
    
    return 0;
}