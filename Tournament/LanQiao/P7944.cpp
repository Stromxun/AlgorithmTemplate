#include<iostream>
using namespace std;
const int maxa = 1e3 + 10;
int a[maxa], n;

int main()
{
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = 0xfffffff;
    for(int i = 1; i <= n; i++){
        if(a[i + 1] < a[i]){
            int t = a[i] - a[i + 1];
            ans = max(t, ans);
        }
    }
    cout << ans;
    return 0;
}