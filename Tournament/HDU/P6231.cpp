#include<iostream>
using namespace std;

const int MAXA = 1e5 + 10;
int a[MAXA];
int n, k;
long long m;

bool check(int mid)
{
    long long ans = 0;
    int num = 0;
    int j = 1;
    for(int i = 1; i <= n; i++){
        if(a[i] >= mid) num++;
        if(num == k){
            ans += n - i + 1;
            while(a[j] < mid){
                ans += n - i + 1;
                j++;
            }
            num--;
            j++;
        }
    }
    return (ans >= m) ? true : false;
}

int main()
{
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d %d %lld", &n, &k, &m);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        int l = 1, r = 1e9;
        while(l < r){
            int mid = (l + r) >> 1;
            if(check(mid)) l =  mid + 1;
            else r = mid;
        }
        printf("%d\n", l - 1);
    }
    return 0;
}
