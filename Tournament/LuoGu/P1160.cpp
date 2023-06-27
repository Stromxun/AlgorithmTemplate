#include<iostream>
#include<list>
using namespace std;

const int MaxN = 1e5 + 10;

list<int>::iterator it[MaxN];
bool erase[MaxN];

int main(){
    int n, m;  scanf("%d", &n);
    list<int> node; node.push_back(1);
    it[1] = node.begin();
    for(int i = 2; i <= n; i++){
        int k, p; scanf("%d %d", &k, &p);
        if(p == 0) it[i] = node.insert(it[k], i);
        else if(p == 1){
            auto nextIt = next(it[k]);
            it[i] = node.insert(nextIt, i);
        }
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int x;
        scanf("%d", &x);
        if(!erase[x]) node.erase(it[x]);
        erase[x] = true;
    }
    for(int i : node){
        printf("%d ", i);
    }
    return 0;
}