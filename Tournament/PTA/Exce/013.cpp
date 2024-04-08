#include<iostream>
using namespace std;

int main()
{
    long long ans = 0;
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        long long t = 1;
        for(int j = 1; j <= i; j++){
            t *= j;
        }
        ans += t;
    }
    cout << ans << endl;
    return 0;
}