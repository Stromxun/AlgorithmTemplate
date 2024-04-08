#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAXA = 1e5 + 10;
int n;
int a[MAXA];
struct Node {
    int a, b;
} p[MAXA];
long double dp[MAXA][2];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i < n; i++){
        scanf("%d %d", &p[i].a, &p[i + 1].b);
    }
    dp[1][0] = a[1] - a[0];
    dp[1][1] = dp[1][0] + p[1].a / 0.7;
    for(int i = 1; i < n; i++){
        dp[i + 1][1] = dp[i][0] + p[i + 1].a / 0.7 + a[i + 1] - a[i];
        if(p[i + 1].a > p[i + 1].b){
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + (p[i + 1].a - p[i + 1].b) / 0.7);
        }else{
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + (p[i + 1].b - p[i + 1].a) / 1.3);
        }
        dp[i + 1][0] = min(dp[i][1] + p[i + 1].b / 1.3, dp[i][0] + a[i + 1] - a[i]);
    }
    printf("%.2Lf", round(dp[n][0]*100)/100);
    return 0;
}
