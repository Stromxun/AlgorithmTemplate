#include<iostream>
#include<algorithm>
using namespace std;
const int MAXA = 1e5 + 10;

int a[MAXA], n, c;

bool check(int mid)
{
    int  cnt = 1, place = 1;
    for(int i = 1; i <= n; i++){
        if(a[i] - a[place] >= mid){
            cnt++;
            place = i;
        }
    }
    if(cnt >= c) return true;
    else return false;
}

int main()
{
    scanf("%d %d", &n, &c);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int l = 1, r = a[n] - a[1];
    int ans = 0;
    while(l < r){
        int mid = (r + l) >> 1;
        if(check(mid)){
            l = mid + 1;
            ans = mid;
        }else r = mid;
    }
    printf("%d", ans);
    return 0;
}