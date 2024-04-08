#include<iostream>
#include<string>
using namespace std;

string s;

int main()
{
    int n;
    cin >> n >> s;
    for(int i = 2; i <= n; i++){
        string t;
        cin >> t;
        int k = s.find(t[0]);
        s.erase(k,1);
        s.insert(k, t);
    }
    for(auto i : s)
        if(i != '*') cout << i;
    return 0;
}