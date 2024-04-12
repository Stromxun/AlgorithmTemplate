#include<iostream>
using namespace std;

int slove(int num)
{
    int ans = 0;
    for(int i = 2; i * i<= num; i++){
        if(num % i == 0) ans++;
    }
    return ans;
}

int main()
{
    int res = 0, ans;
    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= 6; j++){
            int n; cin >> n;
            int t = slove(n);
            if(t > res){
                res = t;
                ans = n;
            }
        }
    }
    cout << ans;
    return 0;
}