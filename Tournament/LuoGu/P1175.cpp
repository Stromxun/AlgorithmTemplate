#include<bits/stdc++.h>
using namespace std;

const int Maxa = 110;

char ans[Maxa];

stack<char> st;
stack<int> it, tt;

int main()
{
    int n = 0;
    char c;
    string str;
    cin >> str;
    int len = str.size();
    for(int i = 0; i < len; i++){
        c = str[i];
        if(c <= '9' && c >= '0'){
            ans[++n] = c;
        }else if(c == '+' || c == '-'){
            while(!st.empty() && (st.top() != '(')){
                ans[++n] = st.top();
                st.pop();
            }
            st.push(c);
        }else if(c == '*' || c == '/'){
            while(!st.empty() && st.top() == '^'){
                ans[++n] = st.top();
                st.pop();
            }
            st.push(c);
        }else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                ans[++n] = st.top();
                st.pop();
            }
            st.pop();
        }else{
            st.push(c);
        }
    }
    while(!st.empty()){
        ans[++n] = st.top();
        st.pop();
    }
    for(int i = 1; i <= n; i++){
        printf("%c ", ans[i]);
    }
    printf("\n");
    for(int i = 1; i <= n; i++){
        c = ans[i];
        if(c <= '9' && c >= '0'){
            it.push(ans[i] - '0');
        }else{
            int b = it.top();
            it.pop();
            int a = it.top();
            it.pop();
            switch(c){
                case '+': it.push(a + b); break;
                case '-': it.push(a - b); break;
                case '*': it.push(a * b); break;
                case '/': it.push((int) a / b); break;
                case '^': it.push((int) pow(a,b)); break;
            }
            while(!it.empty()){
                tt.push(it.top());
                it.pop();
            }
            while(!tt.empty()){
                it.push(tt.top());
                printf("%d ", tt.top());
                tt.pop();
            }
            for(int j = i + 1; j <= n; j++){
                printf("%c ", ans[j]);
            }
            printf("\n");
        }
    }
    return 0;
}