#include<iostream>
#include<algorithm>
using namespace std;
const int MAXA = 1e3 + 10;

struct node {
    int date, num;

    bool operator < (const node a) const {
        if(num == a.num) return date < a.date;
        return num > a.num;
    }
} a[MAXA];

int main()
{
    int t; scanf("%d", &t);
    while(t--){
        int n, ans = 0; scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i].date);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i].num);
        sort(a + 1, a + n + 1);
        for(int i = 1, day = 1; i <= n; i++){
            if(day > a[i].date){
                ans += a[i].num;
            }
            else day++;
        }
        printf("%d\n", ans);
    }
    return 0;
}