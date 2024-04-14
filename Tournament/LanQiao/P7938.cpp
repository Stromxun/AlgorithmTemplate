#include<iostream>
using namespace std;

char a[31][41];

int w[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(int x, int y)
{
    a[x][y] = '2';
    for(int i = 0; i < 4; i++){
        int xx = x + w[i][0];
        int yy = y + w[i][1];
        if(a[xx][yy] == '0'){
            dfs(xx, yy);
        }
    }
}

int main()
{
    int ans = 0;
    for(int i = 1; i <= 30; i++){
        for(int j = 1; j <= 40; j++){
            cin >> a[i][j];
        }
    }
    dfs(1, 1);
    for(int i = 1; i <= 30; i++){
        for(int j = 1; j <= 40; j++){
            if(a[i][j] == '2'){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}