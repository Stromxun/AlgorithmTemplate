#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXA = 1e3 +10;
int dp[MAXA][MAXA];
int main()
{
    char x[MAXA], y[MAXA];
    while(scanf("%s %s", x, y) == 2){
        int len_x = strlen(x), len_y = strlen(y);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= len_x; i++){
            for(int j = 1; j <= len_y; j++){
                if(x[i-1] == y[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        printf("%d", dp[len_x][len_y]);
    }
    return 0;
}