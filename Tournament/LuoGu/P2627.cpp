#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
const int MAXA = 1e5 + 10;
long long f[MAXA];
deque<long long> dq;
int main()
{
    int n, k; scanf("%d %d", &n, &k);
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &f[i]);
        ans += f[i];
        if(i > k + 1){
            f[i] += f[dq.front()];
        }
        while(!dq.empty() && f[dq.back()] > f[i]) dq.pop_back();
        dq.push_back(i);
        while(!dq.empty() && dq.front() < i - k) dq.pop_front();
    }
    printf("%lld\n", ans - f[dq.front()]);
    return 0;
}