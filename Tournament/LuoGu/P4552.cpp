#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

const int MAXA = 1e5 + 10;

long long a[MAXA], D, l = 0, r = 0;

int main()
{
    int n; scanf("%d", &n);
    if(n <= 1){
        printf("0\n0");
        return 0;
    }
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    for(int i = 2; i <= n; i++){
        D = a[i] - a[i - 1];
        if(D > 0) l += D;
        else r -= D;
    }
    printf("%lld\n%lld", max(l, r), abs(l - r) + 1);
    return 0;
}