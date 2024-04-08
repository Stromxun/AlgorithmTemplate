#include<iostream>
using namespace std;

const int maxa = 1e3 + 10;

int t, m;
int w[maxa], v[maxa];
int dp[maxa][maxa];

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    cin >> t >> m;
    for(int i = 1; i <= m; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= t; j++){
            if(w[i] > j){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[m][t] << endl;
    return 0;
}