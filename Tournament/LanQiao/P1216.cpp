#include <iostream>
#include <queue>
using namespace std;
const int maxa = 1e2 + 10;
int a[maxa][maxa];
int n, m, ans;
int x1, y1, x2, y2;
int w[4][2] = {{1, 0},{0,1},{-1,0},{0,-1}};
bool b[maxa][maxa];
struct Node {
    int x, y;
    int n;
};
queue<Node> q;
void bfs()
{
    q.push({x1, y1, 0});
    b[x1][y1] = true;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        int x = t.x, y = t.y;
        if(x == x2 && y == y2) ans = min(ans, t.n);
        for(int i = 0; i < 4; i++){
            int xx = x + w[i][0], yy = y + w[i][1];
            if(b[xx][yy] || xx < 1 || xx > n || yy < 1 || yy > m) continue;
            q.push({xx, yy, t.n + 1});
            b[xx][yy] = true;
        }
    }
}

int main()
{
  // 请在此输入您的代码
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;
    bfs();
    if(b[x2][y2]) cout << ans;
    else cout << -1;
    return 0;
}