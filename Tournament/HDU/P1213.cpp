#include<iostream>
using namespace std;

const int MAXA = 1e5 + 10;
int a[MAXA];
int n, m;

void init_set()
{
    for(int i = 1; i <= n; i++) a[i] = i;
}

int find_set(int x)
{
    return x == a[x] ? x : find_set(a[x]);
}

void merge_set(int x, int y)
{
    x = find_set(x);
    y = find_set(y);
    if(x != y) a[x] = a[y];
}

int main(){
    int t; scanf("%d",&t);
    while (t--){
        scanf("%d %d", &n, &m);
        init_set();
        for(int i = 1; i <= m; i++){
            int a, b; scanf("%d %d", &a, &b);
            merge_set(a, b);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(i == a[i]) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}