#include<bits/stdc++.h>
using namespace std;

const int Maxa = 2e6 + 10;

int a[Maxa];

deque<int> dq;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <=n ; i++){
        scanf("%d", &a[i]);
    }
    printf("0\n");
    for(int i = 1; i < n; i++){
        while(!dq.empty() && a[dq.back()] > a[i]) dq.pop_back();
        dq.push_back(i);
        while(!dq.empty() && dq.front() <= i - m) dq.pop_front();
        printf("%d\n", a[dq.front()]);
    }
}