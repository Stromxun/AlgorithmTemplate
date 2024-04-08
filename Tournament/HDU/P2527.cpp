#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    while(n--){
        priority_queue<int, vector<int>, greater<int>> q;
        string s;
        int m; cin >> m;
        cin >> s;
        sort(s.begin(), s.end());
        int num = 1;
        for(int i = 1; i <= s.length(); i++){
            if(s[i] != s[i - 1]){
                q.push(num);
                num = 1;
            }else num = 1;
        }
        int ans = 0;
        if(q.size() == 1) ans = s.length();
        while(q.size() > 1){
            int a = q.top(); q.pop();
            int b = q.top(); q.pop();
            q.push(a + b);
            ans += a + b;
        }
        q.pop();
        if(m < ans) cout << "no" << endl;
        else cout << "yes" << endl;
    }
    return 0;
}