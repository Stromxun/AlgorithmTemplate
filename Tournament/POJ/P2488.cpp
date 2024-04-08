#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int MAXA = 30;

int p, q;
int cnt, k;
bool ans = 0;
bool vis[MAXA][MAXA];
int w[8][2] = {{-1, -2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
deque<pair<int, int>> dq;

void dfs(int x, int y, int t)
{
    if(t == cnt){
        ans = 1;
        return;
    }
    for(int i = 0; i < 8; i++){
        int dx = x + w[i][0], dy = y + w[i][1];
        if(dx < 1 || dx > p || dy < 1 || dy > q) continue;
        if(vis[dx][dy] == 1) continue;
        vis[dx][dy] = 1;
        dq.push_back(make_pair(dx, dy));
        dfs(dx, dy, t + 1);
        if(ans == 1) return;
        vis[dx][dy] = 0;
        dq.pop_back();
    }
}

int main()
{
    int n; scanf("%d", &n);
    for(k = 1; k <= n; k++){
        memset(vis, 0, sizeof(vis));
        scanf("%d %d", &p, &q);
        cnt = p * q, ans = 0;
        // for(int i = 1; i <= p; i++){
        //     for(int j = 1; j <= q; j++){
        //         vis[i][j] = 1;
        //         dq.push_back(make_pair(i, j));
        //         dfs(i, j, 1);
        //         if(ans == 1) break;
        //         vis[i][j] = 0;
        //         dq.pop_back();
        //     }
        //     if(ans == 1) break;
        // }
        vis[1][1] = 1;
        dq.push_back(make_pair(1, 1));
        dfs(1, 1, 1);
        printf("Scenario #%d:\n", k);
        if(ans == 1){
            while(dq.size()){
            pair<int, int> p = dq.front();
            printf("%c%d", (char)(p.second + 64), p.first);
            dq.pop_front();
        }
        }else printf("impossible");
        printf("\n\n");
        dq.clear();
    }
    return 0;
}