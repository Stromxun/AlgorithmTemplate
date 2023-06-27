#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int Maxa = 1e5 + 10;

struct Node{
    int id;
    int sum;
} a[Maxa];

bool cmp(Node x, Node y)
{
    return x.sum < y.sum;
}

int main()
{
    int n, k, num;
    scanf("%d %d", &n, &k);
    while(n != 0 && k != 0){
        a[0].id = 0, a[0].sum = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &num);
            a[i].id = i;
            a[i].sum = a[i-1].sum + num;
        }
        sort(a, a + n + 1, cmp);
        while(k--){
            int t; scanf("%d", &t);
            int ans[4];
            int i = 0, j = 1, mina = 0x7fffffff;
            while(i <= n && j <= n){
                int temp = a[j].sum - a[i].sum;
                if(abs(temp - t) < mina){
                    ans[1] = temp;
                    ans[2] = a[i].id;
                    ans[3] = a[j].id;
                    mina = abs(temp - t);
                }
                if(temp > t){
                    i++;
                }else if(temp < t){
                    j++;
                }else break;
                if(i == j) j++;
            }
            if(ans[2] > ans[3]) swap(ans[2], ans[3]);
            printf("%d %d %d\n", ans[1], ans[2] + 1, ans[3]);
        }
        scanf("%d %d", &n, &k);
    }
    return 0;
}