#include<iostream>
#include<algorithm>
using namespace std;

int a[31][21];
int maxa = 0;

void dfs(int n, int m)
{
    for(int i = -5; i <= 5; i++){
        for(int j = -5; j <= 5; j++){
            if(n + i < 1 || n + i > 30 || m + j < 1 || m + j > 20) continue;
            if(abs(i) + abs(j) <= 5){
                maxa = max(maxa, abs(a[n][m] - a[n + i][m + j]));
            }
        }
    }
}

int main()
{
    for(int i = 1; i <= 30; i++){
        for(int j = 1; j <= 20; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= 30; i++){
        for(int j = 1; j <= 20; j++){
            dfs(i, j);
        }
    }
    cout << maxa;
    return 0;
}