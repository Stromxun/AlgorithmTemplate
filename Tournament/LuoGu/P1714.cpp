#include<bits/stdc++.h>
using namespace std;

const int Maxa = 5e5 + 10;

deque<int> dq;

int a[Maxa];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        a[i] = a[i] + a[i - 1];
    }
    int ans = -1e8;
    dq.push_back(0);
    for(int i = 1; i <= n; i++){
        while(!dq.empty() && dq.front() < i - m) dq.pop_front();
        if(dq.empty()) ans = max(ans, a[i]);
        else ans = max(ans, a[i] - a[dq.front()]);
        while(!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
        dq.push_back(i);
    }
    printf("%d\n", ans);
    return 0;
}