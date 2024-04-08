#include<iostream>
using namespace std;
typedef long long ll;
const int MAXA = 5e5 + 10;

int n;
int a[MAXA], b[MAXA];
ll cnt = 0;

void merge(int L, int mid, int R)
{
    int i = L, j = mid + 1, t = 0;
    while(i <= mid && j <= R){
        if(a[i] > a[j]){
            b[t++] = a[j++];
            cnt += mid - i + 1;
        }else b[t++] = a[i++];
    }
    while(i <= mid) b[t++] = a[i++];
    while(j <= R) b[t++] = a[j++];
    for(int i = 0; i < t; i++) a[L + i] = b[i];
}

void merge_sort(int L, int R)
{
    if(L < R){
        int mid = (L + (R - L) / 2);
        merge_sort(L, mid);
        merge_sort(mid + 1, R);
        merge(L, mid, R); // 合并
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    merge_sort(1, n);
    printf("%lld", cnt);
}