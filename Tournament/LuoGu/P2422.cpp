#include<bits/stdc++.h>
using namespace std;
#define int long long

const int Maxa = 1e5 + 10;

int a[Maxa], sum[Maxa], l[Maxa];

stack<int> st;

signed main()
{
    int n; scanf("%lld", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        sum[i] = a[i] + sum[i - 1];
    }
    long long ans = 0;
    sum[n+1]=a[n];
    for(int i = 1; i <= n + 1; i++){
        while(!st.empty() && a[i] <= a[st.top()]){
            ans = max(ans, (sum[i - 1] - sum[l[st.top()]]) * a[st.top()]);
            st.pop();
        }
        if(!st.empty()) l[i] = st.top();
        else l[i] = 0;
        st.push(i);
    }
    printf("%lld", ans);
    return 0;
}