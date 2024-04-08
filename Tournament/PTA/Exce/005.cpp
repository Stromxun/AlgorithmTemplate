#include<iostream>
using namespace std;
const int maxa = 1e3 + 10;

struct Node {
    string num;
    int cnt;
} a[maxa];

int main()
{
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int n, m;
    cin >> n;
    for(int i = 1; i <= n; i++){
        string x;
        int y, z;
        cin >> x >> y >> z;
        a[y].num = x;
        a[y].cnt = z;
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        int t; cin >> t;
        cout << a[t].num << ' ' << a[t].cnt << endl;
    }
    return 0;
}