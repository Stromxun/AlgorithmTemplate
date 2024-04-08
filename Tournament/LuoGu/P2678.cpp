#include<iostream>
using namespace std;

long long k, n, m, a[50010];

int check(int mid)
{
    int cnt = 0;
    int i = 0, now = 0;
    while(i < n + 1){
        i++;
        if(a[i] - a[now] < mid){
            cnt++;
        }else{
            now = i;
        }
    }
    if(cnt <= m) return 1;
    return 0;
}

int main()
{
    cin >> k >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    a[0] = 0, a[n + 1] = k;

    if(n == 0){
        cout << k;
        return 0;
    }

    long long l = 1, r = 1e10;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l;
    return 0;
}