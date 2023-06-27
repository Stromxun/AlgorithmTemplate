#include<iostream>
#include<deque>
using namespace std;

const int MAXA = 1e6 + 10;

int a[MAXA];

deque<int> dq;

int main(){
    int n, k; scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++){
        while(!dq.empty() && a[dq.back()] > a[i]) dq.pop_back();
        dq.push_back(i);
        if(i >= k){
            while(!dq.empty() && dq.front() <= i - k) dq.pop_front();
            printf("%d ", a[dq.front()]);
        }
    }
    printf("\n");
    while(!dq.empty()) dq.pop_back();
    for(int i = 1; i <= n; i++){
        while(!dq.empty() && a[dq.back()] < a[i]) dq.pop_back();
        dq.push_back(i);
        if(i >= k){
            while(!dq.empty() && dq.front() <= i - k) dq.pop_front();
            printf("%d ", a[dq.front()]);
        }
    }
    return 0;
}