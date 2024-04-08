#include<iostream>
// #include<bits/stdc++.h>
using namespace std;
const int MAXA = 1e5 + 10;
int n, C, dp[MAXA];
int w[MAXA], c[MAXA], m[MAXA];
int new_n;
int new_w[MAXA], new_c[MAXA], new_m[MAXA];
int main()
{
    cin >> n >> C;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> c[i] >> m[i];
    }
    int new_n = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m[i]; j <<= 1){
            m[i] -= j;
            new_c[++new_n] = j * c[i];
            new_w[new_n] = j * w[i];
        }
        if(m[i]){
            new_c[++new_n] = m[i] * c[i];
            new_w[new_n] = m[i] * w[i];
        }
    }
    for(int i = 1; i <= new_n; i++){
        for(int j = C; j >= new_c[i]; j--){
            dp[j] = max(dp[j], dp[j - new_c[i]] + new_w[i]);
        }
    }
    cout << dp[C] << endl;
    return 0;
}