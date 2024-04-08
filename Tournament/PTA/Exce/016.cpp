#include<iostream>
using namespace std;

int a[]{7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};

int z[]{1,0,(int)'X'-(int)'0',9,8,7,6,5,4,3,2};

int main()
{
    int n; cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        // cout << s.length() << endl;
        long long t = 0;
        for(int j = 0; j < 17; j++){
            t += (s[j] - '0') * a[j];
        }
        t = t % 11;
        if(s[17] == z[t] + '0') ans++;
        else{
            cout << s << endl;
        }
    }
    if(ans == n) cout << "All passed" << endl;
    return 0;
}