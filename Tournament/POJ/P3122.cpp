#include<iostream>
#include<math.h>
using namespace std;
const int MAXA = 1e4 + 10;
const double PI = acos(-1.0);
#define eps 1e-5

int n, m;
double a[MAXA];

bool check(double mid)
{
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += (int)(a[i] / mid);
    }
    if(sum >= m) return true;
    else return false;
}

int main()
{
    int t;  scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        m++;
        double maxx = 0;
        for(int i = 1; i <= n; i++){
            int r;
            scanf("%d", &r);
            a[i] = PI * r * r;
            if(maxx < a[i]) maxx = a[i];
        }
        double l = 0, r = maxx;
        while((r -  l) > eps){
            double mid = l + (r - l) / 2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        printf("%.4lf\n", l);
    }
    return 0;
}