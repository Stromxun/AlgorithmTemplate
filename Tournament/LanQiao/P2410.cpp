#include<iostream>
#include<algorithm>
using namespace std;

char a[31][61];
int num = 0, res = 0;
int b[35][65] = {0};
int w[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void dfs(int x, int y)
{
    if(x < 1 || x > 30 || y < 1 || y > 60 || a[x][y] == '0' || b[x][y] == 1) return;
    b[x][y] = 1;
    num++;
    for(int i = 0; i < 4; i++){
        int tx = x + w[i][0];
        int ty = y + w[i][1];
        dfs(tx, ty);
    }
}

int main()
{
    char c;
    for(int i = 1; i <= 30; i++){
        for(int j = 1; j <= 60; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= 30; i++){
        for(int j = 1; j <= 60; j++){
            num = 0;
            dfs(i, j);
            res = max(res, num);
        }
    }
    cout << res;
    return 0;
}