#include<iostream>
#include<algorithm>
using namespace std;

const int MAXA = 2e5 + 10;
long long a[MAXA];

int main()
{
    int n; scanf("%d" ,&n);
    long long c; scanf("%lld", &c);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    long long ans = 0;
    for(int i = 1, j = 1, k = 1; i <= n; i++){
        while(j <= n && a[j] - a[i] < c) j++;
        while(k <= n && a[k] - a[i] <= c) k++;
        if(a[j] - a[i] == c && a[k - 1] - a[i] == c && k - 1 >= 1) ans += k - j;
    }
    printf("%lld", ans);
    return 0;
}