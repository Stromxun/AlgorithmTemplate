#include <iostream>
#include <algorithm>
using namespace std;

const int maxa = 1e3 + 10;
int a[maxa][maxa];
bool b[maxa][maxa] = {0};
int w[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int ans = 1;
int n, m;

void dfs(int x, int y)
{
    for(int i = 0; i < 4; i++){
        int tx = x + w[i][0];
        int ty = y + w[i][1];
        if(b[tx][ty] || tx < 1 || tx > n || ty < 1 || ty > m) continue;
        if(__gcd(a[tx][ty], a[x][y]) > 1){
            b[tx][ty] = true;
            ans++;
            dfs(tx, ty);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    int r, c; cin >> r >> c;
    b[r][c] = true;
    dfs(r, c);
    cout << ans;
    return 0;
}