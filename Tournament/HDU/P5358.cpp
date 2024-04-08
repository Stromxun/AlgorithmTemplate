#include<iostream>
#include<algorithm>
using namespace std;

const int Maxa = 1e5 + 10;

long long a[Maxa];

int main()
{
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        a[0] = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            a[i] += a[i - 1];
        }
        long long ans = 0;
        for(int i = 1; i <= 35; i++){
            long long l = 1, r = 0;
            long long mina = 1ll << (i - 1), maxa = (1ll << i) - 1;
            if(i == 1) mina = 0;
            for(int j = 1; j <= n; j++){
                l = max(l, (long long)j);
                while(l <= n && a[l] - a[j - 1] < mina) l++;
                r = max(r, l - 1);
                while(a[r + 1] - a[j - 1] >= mina && a[r + 1] - a[j - 1] <= maxa && r + 1 <= n) r++;
                if(l > r) continue;
                ans += (j * (r - l + 1) + (r + l) * (r - l + 1) / 2) * i;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}