#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q1; // 小根堆
priority_queue<int, vector<int>> q2; // 大根堆

int main()
{
    int n, a; scanf("%d %d", &n, &a);
    q2.push(a); printf("%d\n", q2.top());
    for(int i = 2; i <= n; i++){
        scanf("%d", &a);
        if(a > q2.top()) q1.push(a);
        else q2.push(a);
        while(max(q1.size(), q2.size()) - min(q1.size(), q2.size()) > 1){
            if(q1.size() > q2.size()){
                q2.push(q1.top());
                q1.pop();
            }else {
                q1.push(q2.top());
                q2.pop();
            }
        }
        if(i % 2) printf("%d\n", (q1.size() > q2.size() ? q1.top() : q2.top()));
    }
    return 0;
}