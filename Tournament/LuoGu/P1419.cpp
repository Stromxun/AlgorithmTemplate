#include<iostream>
#include<deque>
using namespace std;
const int MAXA = 1e5 + 10;

int a[MAXA], n, s, t;
double ans = 1e-5, sum[MAXA];

bool check(double mid)
{
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + (double)a[i] - mid;
    }
    deque<int> dq;
    for(int i = s; i <= n; i++){
        while(!dq.empty() && sum[dq.back()] > sum[i - s]) dq.pop_back();
        dq.push_back(i - s);
        while(!dq.empty() && dq.front() < i - t) dq.pop_front();
        if(!dq.empty() && sum[i] - sum[dq.front()] >= 0) return true;
    }
    return false;
}

int main()
{
    scanf("%d %d %d", &n, &s, &t);
    for(int i = 1; i <= n;  i++){
        scanf("%d", &a[i]);
    }
    double l = -100000, r = 100000;
    while(r - l > 1e-5){
        double mid = (l + r) / 2;
        if(check(mid)) ans = l = mid;
        else r = mid;
    }
    printf("%.3lf", ans);
    return 0;
}