#include<bits/stdc++.h>
using namespace std;


stack<int> st;

int main()
{
    int ans, num = 0;
    while(true){
        char c = getchar();
        if(c == '@') break;
        if(c == '.'){
            st.push(num);
            num = 0;
        }else if(c <= '9' && c >= '0'){
            num = c - '0' + num * 10;
        }else{
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            int temp;
            if(c == '+') temp = a + b;
            else if(c == '-') temp = a - b;
            else if(c == '*') temp = a * b;
            else if(c == '/') temp = a / b;
            st.push(temp);
        }
    }
    printf("%d", st.top());
}