#include<bits/stdc++.h>
using namespace std;

stack<int> st;

int main()
{
    char c;
    int a, b;
    scanf("%d", &a);
    st.push(a % 10000);
    while(cin >> c >> b){
        if(c == '*'){
            int a = st.top();
            st.pop();
            st.push((a * b) % 10000);
        }else{
            st.push(b % 10000);
        }
    }
    while(st.size()>=2){
        b = st.top();
        st.pop();
        a = st.top();
        st.pop();
        st.push((a + b) % 10000);
    }
    printf("%d", st.top());
    return 0;
}