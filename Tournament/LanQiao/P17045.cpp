#include<iostream>
using namespace std;
const int maxa = 3e1 + 10;
int a[maxa][maxa];

int slove(int x, int  y)
{
    int ans = 0;
    for(int i = x; i <= x + 4; i++){
        for(int j = y; j <= y + 4; j++){
            ans += a[i][j];
        }
    }
    return ans;
}

int main()
{
    for(int i = 1; i <= 30; i++){
        for(int j = 1; j <= 20; j++){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int i = 1; i <= 30 - 4; i++){
        for(int j = 1; j <= 20 - 4; j++){
            ans = max(ans, slove(i, j));
        }
    }
    cout << ans;
    return 0;
}