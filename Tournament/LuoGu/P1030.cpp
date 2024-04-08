#include<iostream>
#include<string>

using namespace std;

void solve(string first, string after)
{
    if(first.size() <= 0) return;
    char root = after.back();
    printf("%c", root);
    int k = first.find(root);
    solve(first.substr(0, k), after.substr(0, k));
    solve(first.substr(k + 1), after.substr(k, first.size() - k - 1));
}

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    solve(s1, s2);
    return 0;
}