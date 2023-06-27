#include<iostream>
using namespace std;

const int Maxa = 1e5 + 10;

int a[Maxa];

int main()
{
    int t; scanf("%d", &t);
    while(t--){
        int n, s; scanf("%d %d", &n, &s);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        int sum = a[0], i = 1, j = 0, ans = 0x7fffffff;
        while(j <= n){
            if(sum >= s){
                ans = min(ans, j - i + 1);
                sum -= a[i];
                i++;
                if(i > j){
                    sum = a[i];
                    j++;
                }
            }
            if(sum < s){
                j++;
                sum += a[j];
            }
        }
        if(ans != 0x7fffffff) printf("%d\n", ans);
        else printf("0\n");
    }
    return 0;
}