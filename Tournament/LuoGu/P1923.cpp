#include<iostream>
using namespace std;
const int MAXA = 5e6 + 10;

int n, k;
int a[MAXA];

int quick_sort(int L, int R)
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
    if(L <= j && k + 1 <= j) return quick_sort(L, j);
    if(i <= R && k + 1 >= i) return quick_sort(i, R);
    return a[k + 1];
}

int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    printf("%d", quick_sort(1, n));
    return 0;
}