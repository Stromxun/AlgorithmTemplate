#include<iostream>
using namespace std;

const int Maxa = 1e5 + 10;

int a[Maxa];

int main(){
    int t; scanf("%d", &t);
    int temp = t;
    while(temp-- > 0){
        int n; scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        int start = 1, end = 1, p = 1;
        int maxsum = a[1];
        for(int i = 2; i <= n; i++){
            if(a[i - 1] + a[i] >= a[i])
                a[i] = a[i - 1] + a[i];
            else p = i;
            if(a[i] > maxsum){
                maxsum = a[i];
                start = p;
                end = i;
            }
        }
        printf("Case %d:\n", t - temp);
        printf("%d %d %d\n", maxsum, start, end);
        if(temp != 1) printf("\n");
    }
}