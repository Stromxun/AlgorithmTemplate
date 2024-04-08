#include<iostream>
#include<string.h>
using namespace std;

const int Maxa = 1e5 + 10;

int a[Maxa], D[Maxa];

int main()
{
    int n;
    while(~scanf("%d", &n)){
        memset(a, 0, sizeof(a)), memset(D, 0, sizeof(D));
        for(int i = 1; i <= n; i++){
            int l, r; scanf("%d %d", &l, &r);
            D[l]++, D[r + 1]--;
        }
        for(int i = 1; i <= n; i++){
            a[i] = a[i - 1] + D[i];
            if(i != n) printf("%d ", a[i]);
            else printf("%d\n", a[i]);
        }
    }
    return 0;
}