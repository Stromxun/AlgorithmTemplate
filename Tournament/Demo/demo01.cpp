#include<iostream>
using namespace std;

int main()
{
    // 
    int n = 15;
    int ans = 0;
    while(n >= 4){
        int t = n / 4;
        ans += t;
        n %= 4;
        n += t;
    }
    cout << ans;
    return 0;
}