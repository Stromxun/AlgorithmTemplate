#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int MAXA = 1e6 + 10;
int a[MAXA];
set<int> s;

int main()
{
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        s.clear();
        for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
        }
        int l = 1, r = 1, ans = 0;
        while(r <= n){
            while(r <= n && !s.count(a[r])) s.insert(a[r++]);
            ans = max(ans, r - l);
            s.erase(a[l++]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}