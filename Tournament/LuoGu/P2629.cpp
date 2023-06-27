#include<bits/stdc++.h>
using namespace std;

const int Maxa = 2e6 + 10;

int a[Maxa];

deque<int> dq;

int main()
{
    int n; scanf("%d", &n);
    int ans = 0;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = n + 1; i <= 2 * n - 1; i++) a[i] = a[i - n];
    for(int i = 1; i <= 2 * n - 1; i ++) a[i] = a[i] + a[i - 1];
    for(int i = 1; i <= 2 * n - 1; i++){
        while(!dq.empty() && dq.front() < i - n + 1) dq.pop_front();
        while(!dq.empty() && a[dq.back()] > a[i]) dq.pop_back();
        dq.push_back(i);
        if(i - n + 1 > 0 && a[dq.front()] - a[i - n] >= 0) ans++;
    }
    printf("%d\n", ans);
    return 0;
}