#include<bits/stdc++.h>
using namespace std;

stack<char> st;

int main()
{
    char c;
    while((c = getchar()) != '@'){
        if(c == '('){
            st.push(c);
        }else if(c == ')'){
            if(st.empty()){
                printf("NO");
                return 0;
            }else{
                st.pop();
            }
        }
    }
    if(st.empty()) printf("YES");
    else printf("NO");
    return 0;
}