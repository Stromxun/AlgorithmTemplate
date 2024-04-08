#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int, int> P;

struct cmp
{
    bool operator()(const P p1, const P p2){
        return p1.first > p2.first;
    }
};

priority_queue<P, vector<P>, cmp> q;
const int MAXA = 1e4 + 10;
int a[MAXA], b[MAXA], c[MAXA], x[MAXA];

inline int solve(int num)
{
    return a[num] * x[num] * x[num] + b[num] * x[num] + c[num];
}

int main()
{
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        x[i]++;
        q.push(make_pair(solve(i), i));
    }
    for(int i = 1; i <= m; i++){
        P temp = q.top(); x[temp.second]++;
        printf("%d ", temp.first);
        if(i == m) continue;
        q.pop();
        q.push(make_pair(solve(temp.second), temp.second));
    }
    return 0;
}