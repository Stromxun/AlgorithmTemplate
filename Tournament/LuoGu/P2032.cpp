#include<bits/stdc++.h>
using namespace std;

const int Maxa = 2e6 + 10;

int a[Maxa];

deque<int> dq;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++){
        while(!dq.empty() && a[dq.back()] < a[i]) dq.pop_back();
        dq.push_back(i);
        if(i >= k){
            if(!dq.empty() && dq.front() <= i - k) dq.pop_front();
            printf("%d\n",a[dq.front()]);
        }
    }
    return 0;
}