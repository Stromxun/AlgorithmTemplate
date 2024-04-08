#include<iostream>
#include<cstring>
using namespace std;
const int MAXA = 1e6 + 10;

long long diff[MAXA], need[MAXA], r[MAXA], d[MAXA], s[MAXA], t[MAXA];
int n, m; 

bool check(int mid)
{
    memset(diff, 0, sizeof(diff));
    for(int i = 1; i <= mid; i++){
        diff[s[i]] += d[i];
        diff[t[i] + 1] -= d[i];
    }
    for(int i = 1; i <= n; i++){
        need[i] = need[i - 1] + diff[i];
        if(need[i] > r[i]) return false;
    }
    return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &r[i]);
    }
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &d[i], &s[i], &t[i]);
    }
    if(check(m)){
        printf("0");
        return 0;
    }
    int l = 1, r = m;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid + 1;
        else r = mid;
    }
    printf("-1\n%d", l);
    return 0;
}