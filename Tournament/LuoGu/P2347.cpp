#include<iostream>
using namespace std;
const int MAXA = 6e3 + 10;
int a[7], n = 0, sum = 0, dp[MAXA], ans = 0;
int c[7] = {0, 1, 2, 3, 5, 10, 20};
int new_n = 0;
int new_c[MAXA];
int main()
{
    for(int i = 1; i <= 6; i++){
        cin >> a[i];
        n += a[i];
    }
    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= a[i]; j <<= 1){
            a[i] -= j;
            new_c[++new_n] = j * c[i];
        }
        if(a[i]){
            new_c[++new_n] = a[i] * c[i];
        }
    }
    for(int i = 1; i <= new_n; i++){
        sum += new_c[i];
    }
    dp[0] = 1;
    for(int i = 1; i <= new_n; i++){
        for(int j = sum; j >= new_c[i]; j--){
            dp[j] += dp[j - new_c[i]];
        }
    }
    for(int i = 1; i <= sum; i++){
        if(dp[i]) ans++;
    }
    cout << "Total=" << ans << endl;
    return 0;
}