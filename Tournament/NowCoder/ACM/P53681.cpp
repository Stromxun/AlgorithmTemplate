#include<iostream>
#include<algorithm>
using namespace std;

const int MAXA = 500000 + 10;

struct Node
{
    int a, b;
    int w;
    bool operator < (const Node &p) const {
        if(w > 0 && p.w > 0) return a < p.a;
        else if(w < 0 && p.w < 0) return b > p.b;
        else return w > p.w; //降序
    }
} arr[MAXA];

int main()
{
    int t; scanf("%d",&t);
    while(t--){
        int n, m; scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++){
            scanf("%d %d", &arr[i].a, &arr[i].b);
            arr[i].w = arr[i].b - arr[i].a;
        }
        sort(arr + 1, arr + n + 1);
        long long sum = m;
        int i;
        for(i = 1; i <= n; i++){
            if(sum < arr[i].a) break;
            sum += arr[i].w;
        }
        if(i != n + 1) printf("No\n");
        else printf("Yes\n");
    }
}