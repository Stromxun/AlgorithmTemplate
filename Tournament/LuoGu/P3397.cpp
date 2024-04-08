#include<iostream>
using namespace std;

const int Maxa = 1e3 + 10;

int D[Maxa][Maxa];

int main()
{
    int  n, m; scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        D[x1][y1]++;
        D[x2 + 1][y1]--;
        D[x1][y2 + 1]--;
        D[x2 + 1][y2 + 1]++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            D[i][j] += D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1];
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }
    return 0;
}