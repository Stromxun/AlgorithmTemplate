#include<bits/stdc++.h>
using namespace std;
const int MIN = -19260817;
int n, a[200010];

int check(int L, int R)
{
    if(L == R) return a[L];
    int mid = (L + (R - L) / 2);
    int sum = 0, res1 = MIN, res2 = MIN;
    for(int i = mid; i >= L; i--)
        sum += a[i], res1 = max(res1, sum);
    sum = 0;
    for(int i = mid + 1; i <= R; i++)
        sum += a[i], res2 = max(res2, sum);
    return max(max(check(L, mid), check(mid + 1, R)), res1 + res2);
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    printf("%d", check(1, n));
    return 0;
}