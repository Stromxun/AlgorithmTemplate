#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

const int Maxa = 1e5 + 10;

int D[Maxa];
map<pair<int, int>, bool> mp;

int main()
{
    int n, i, h, r;
    scanf("%d %d %d %d", &n, &i, &h, &r);
    for(int i = 1; i <= r; i++){
        int a, b; scanf("%d %d", &a, &b);
        if(a > b) swap(a, b);
        // 去重
        if(mp[make_pair(a, b)]) continue;
        D[a + 1] --, D[b] += 1;
        mp[make_pair(a, b)] = true;
    }
    for(int i = 1; i <= n; i++){
        D[i] = D[i - 1] + D[i];
        printf("%d\n", h + D[i]);
    }
    return 0;
}