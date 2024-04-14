#include<iostream>
#include<stack>
using namespace std;
const int maxa = 1e6 + 10;

char a[maxa];
int s[maxa];

int main()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int top = 0;
    for(int i = 1; i <= n; i++){
        while(m && top && a[s[top - 1]] > a[i] ){
            top--;
            m--;
        }
        s[top++] = i;
    }
    while(m){
        top--;
        m--;
    }
    for(int i = 0; i < top; i++){
        cout << a[s[i]];
    }
    return 0;
}