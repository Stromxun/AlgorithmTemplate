#include<iostream>
#include<algorithm>
using namespace std;

const int maxa = 2e1 + 10;
int n;
int a[maxa];
int w[maxa][maxa];
int dp[maxa];
int p[maxa], pos;

void dfs(int i)
{
    if(i == 0) return;
    dfs(p[i]);
    cout << i << " ";
}

int main()
{
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = a[i];
    }
    for(int i = 1; i <= n - 1; i++){
        for(int j = i + 1; j <= n; j++){
            cin >> w[i][j];
        }
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < n; j++){
            if(w[j][i] && dp[i] < dp[j] + a[i]){
                dp[i] = a[i] + dp[j];
                p[i] = j;
            }
        }
    }
    int ans = 0, p;
    for(int i = 1; i <= n; i++){
        if(dp[i] > ans){
            ans = dp[i];
            pos = i;
        }
    }
    dfs(pos);
    cout << endl;
    cout << ans << endl;
    return 0;
}