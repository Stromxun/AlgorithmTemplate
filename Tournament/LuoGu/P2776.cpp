#include<bits/stdc++.h>
using namespace std;

const int Maxa = 1e5 + 10;

int a[Maxa];

queue<int> q;
queue<int> detail[310];

int main()
{
    int n, m, t;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d\n", &t);
    while(t-- > 0){
        string str;
        int num;
        cin >> str;
        if(str == "push"){
            scanf("%d", &num);
            if(detail[a[num]].empty()) q.push(a[num]);
            detail[a[num]].push(num);
        }else if(str == "pop"){
            printf("%d\n", detail[q.front()].front());
            detail[q.front()].pop();
            if(detail[q.front()].empty()) q.pop();
        }
    }
    return 0;
}