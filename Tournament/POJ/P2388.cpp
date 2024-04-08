#include<iostream>
using namespace std;

const int MAXA = 1e5 + 10;
int a[MAXA];

int quick_sort(int L, int R, int k)
{
    int mid = a[L + (R - L) / 2];
    int i = L, j = R;
    while(i <= j){
        while(a[i] < mid) i++;
        while(a[j] > mid) j--;
        if(i <= j){
            swap(a[i], a[j]);
            i++, j--;
        }
    }
    if(L <= j && k <= j) return quick_sort(L, j + 1, k);
    if(i < R && k >= i) return quick_sort(i, R, k);
    return a[k];
}

int main()
{
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int k = (n >> 1) + 1;
    printf("%d\n", quick_sort(1, n, k));
    return 0;
}