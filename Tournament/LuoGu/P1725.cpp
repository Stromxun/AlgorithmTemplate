#include<bits/stdc++.h>
using namespace std;

const int Maxa = 2e5+10;

int a[Maxa] = {0};

int dp[Maxa];

deque<int> dq;

int main()
{
    memset(dp, 128, sizeof(dp));
    dp[0] = 0;
    int n, l, r;
    scanf("%d %d %d", &n, &l, &r);
    for(int i = 0; i <= n; i++){
        scanf("%d", &a[i]);
    }
    int ans = -2e9;
    for(int i = l; i <= n; i++){
        while(!dq.empty() && dq.front() < i - r) dq.pop_front();
        while(!dq.empty() && dp[dq.back()] < dp[i - l]) dq.pop_back();
        dq.push_back(i - l);
        dp[i] = dp[dq.front()] + a[i];
        if(i + r > n) ans = max(ans, dp[i]);
    }
    printf("%d", ans);
    return 0;
}