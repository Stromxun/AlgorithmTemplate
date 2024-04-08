#include<iostream>
#include<algorithm>
using namespace std;
const int MAXA = 1e2 + 11;

struct node {
    int l, r;

    bool operator < (node b) const{
        if(r == b.r) return l < b.l;
        return r < b.r;
    }

} a[MAXA];

int main()
{
    int n, ans, t = 0; scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &a[i].l, &a[i].r);
    }
    scanf("%d", &ans);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        if(a[i].l >= t){
            ans++;
            t = a[i].r;
        }
    }
    printf("%d", ans);
    return 0;
}