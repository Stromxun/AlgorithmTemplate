#include<iostream>
#include<math.h>
using namespace std;

const int MAXA = 1e5+10;

int D[MAXA];

int main()
{
    int n, m, p;
    long long ans = 0, sum = 0;
    scanf("%d %d",&n, &m);
    if(m <= 1){
        printf("0");
        return 0;
    }
    scanf("%d", &p);
    for(int i = 2; i <= m; i++){
        int temp; scanf("%d", &temp);
        if(p < temp) D[p]++, D[temp]--;
        else D[p]--, D[temp]++;
        p = temp;
    }
    for(int i = 1; i <= n - 1; i++){
        sum += D[i];
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        if(sum != 0) ans += min(a * sum, b * sum + c);
    }
    printf("%lld", ans);
    return 0;
}