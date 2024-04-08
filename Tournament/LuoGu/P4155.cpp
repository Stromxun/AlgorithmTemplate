#include<iostream>
#include<algorithm>
using namespace std;

const int MAXA = 4e5 + 10;

struct warrior{
    int id, L, R;
    bool operator < (const warrior b) const {
        return L < b.L;
    }
} w[MAXA * 2];

int n2;
int go[MAXA][20];

void init()
{
    
}

int main()
{
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        w[i].id = i;
        scanf("%d %d", &w[i].L, &w[i].R);
        if(w[i].R < w[i].L) w[i].R += m;
    }
    sort(w + 1, w + n + 1);
    n2 = n;
    for(int i = 1; i <= n; i++){
        n2++;
        w[n2] = w[i];
        w[n2].L = w[i].L + m;
        w[n2].R = w[i].R + m;
    }
    init();
    for(int i = 1; i <= n; i++){

    }
}