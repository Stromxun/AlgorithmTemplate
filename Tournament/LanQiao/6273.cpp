#include<iostream>
using namespace std;

int a[10];

int main()
{
    string s; cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++){
        a[s[i] - '0']++;
    }
    for(int i = 0; i < 10; i++){
        cout << a[i] << " "; // 输出每个数字出现的次数，空格隔开
    }
    return 0;
}