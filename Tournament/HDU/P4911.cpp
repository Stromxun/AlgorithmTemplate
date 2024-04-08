#include<istream>
using namespace std;
typedef long long ll;
const int MAXA = 1e5 + 10;

ll a[MAXA], cnt, b[MAXA];

void merge(ll L, ll mid, ll R)
{
    ll i = L, j = mid + 1, t = 0;
    while(i <= mid && j <= R){
        if(a[i] > a[j]){
            b[t++] = a[j++];
            cnt += mid - i + 1;
        }else b[t++] = a[i++];
    }
    while(i <= mid) b[t++] = a[i++];
    while(j <= R) b[t++] = a[j++];
    for(i = 0; i < t; i++) a[L + i] = b[i];
}

void merge_sort(ll L, ll R)
{
    if(L < R){
        ll mid = (L + R) / 2;
        merge_sort(L, mid);
        merge_sort(mid + 1, R);
        merge(L, mid, R); // 合并
    }
}

int main()
{
    ll n, k;
    while((scanf("%lld %lld", &n, &k)) != EOF){
        cnt = 0;
        for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
        merge_sort(0, n - 1);
        if(cnt <= k) printf("0\n");
        else printf("%I64d\n", cnt - k);
    }
}