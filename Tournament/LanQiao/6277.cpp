#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    long long n, t, mina = 0xfffffff, cnt, p, ans;
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++){
            cin >> n;
            p = n;
            cnt = 0;
            while(n){
                t = n % 10;
                n /= 10;
                cnt += t;
            }
            if(cnt < mina){
                mina = cnt;
                ans = p;
            }
            mina = min(mina, cnt);
        }
    }
    cout << ans;
    return 0;
}