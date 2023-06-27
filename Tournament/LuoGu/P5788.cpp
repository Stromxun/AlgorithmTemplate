#include<bits/stdc++.h>
using namespace std;

const int Maxa = 3e6 + 10;

int a[Maxa], ans[Maxa];

stack<int> st;

int main()
{
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = n; i >= 1; i--){
        while(!st.empty() && a[st.top()] <= a[i]) st.pop();
        if(st.empty()) ans[i] = 0;
        else ans[i] = st.top();
        st.push(i);
    }
    for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}