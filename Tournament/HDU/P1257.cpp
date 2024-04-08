#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXA = 1e5 + 10;
int a[MAXA], dp[MAXA];
int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        int res = 0;
        for(int i = 1; i <= n; i++){
            dp[i] = 1; 
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                if(a[j] < a[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        printf("%d\n", res);
    }
    return 0;
}