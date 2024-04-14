#include<iostream>
using namespace std;
typedef long long ll;
const int maxa = 1e2 + 10;
int a[maxa];
int n = 10;
int tree[maxa];
void build(ll l = 1, ll r = n, ll p = 1)
{
    if(l == r) tree[p] = a[l];
    else {
        ll mid = (l + r) / 2;
        build(l, mid, p * 2);
        build(mid + 1, r, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }
}

int main()
{
    for(int i = 1; i <= n; i++){
        a[i] = i;
    }
    build();

    cout << "==" << endl;
    return 0;
}