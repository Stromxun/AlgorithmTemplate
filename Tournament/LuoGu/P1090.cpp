#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[10005],b[10005];
int main()
{
    int n,sum = 0;
    cin >> n;
    memset(a, 127, sizeof(a));
    memset(b, 127, sizeof(b));
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 1, j = 0, k = 0, l = 0, w = 0; i < n; i++){
        w = a[j] < b[k] ? a[j++] : b[k++];
        w += a[j] < b[k] ? a[j++] : b[k++];
        b[l++] = w;
        sum += w;
    }
    cout << sum;
    return 0;
}