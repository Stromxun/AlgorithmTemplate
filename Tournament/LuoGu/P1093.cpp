#include<iostream>
#include<algorithm>
using namespace std;

const int MAXA = 3e2 + 10;

struct student
{
    int id;
    int c, m, e;
    int sum;

    bool operator < (const student b) const {
        if(sum == b.sum){
            if(c == b.c){
                return id < b.id;
            }else return c > b.c;
        }else return sum > b.sum;
    }
} st[MAXA];

int main()
{
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        st[i].id = i;
        scanf("%d %d %d", &st[i].c, &st[i].m, &st[i].e);
        st[i].sum = st[i].c + st[i].m + st[i].e;
    }
    sort(st + 1, st + n + 1);
    for(int i = 1; i <= 5; i++){
        printf("%d %d\n", st[i].id, st[i].sum);
    }
}
