#include<iostream>
using namespace std;
const int maxn = 1e3 + 10;

int w[maxn], v[maxn];
int n, m;
int dp[maxn][maxn];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 0; k * w[i] <= j; k++){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]); // 这里k可以取0，所以要加上
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}