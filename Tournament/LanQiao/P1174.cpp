#include <iostream>
using namespace std;
const int maxa = 1e3+10;
int w[maxa];
int v[maxa];
long long a[maxa][maxa];
int main()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    a[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(j >= w[i]){
                a[i][j] = max(a[i - 1][j], a[i - 1][j - w[i]] + v[i]);
            }else{
                a[i][j] = a[i - 1][j];
            }
        }
    }
    cout << a[n][m];
    return 0;
}