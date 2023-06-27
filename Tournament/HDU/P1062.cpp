#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int n;
    scanf("%d\n", &n);
    while(n--){
        stack<char> s;
        while(true){
            char c = getchar();
            if(c == ' ' || c == '\n' || c == EOF){
                while(!s.empty()){
                    printf("%c", s.top());
                    s.pop();
                }
                if(c == '\n' || c == EOF) break;
                printf(" ");
            }else s.push(c);
        }
        printf("\n");
    }
    return 0;
}