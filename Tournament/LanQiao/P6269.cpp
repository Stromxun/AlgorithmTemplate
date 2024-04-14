#include<iostream>
using namespace std;

int main()
{
    int p; cin >> p;
    int t = p % 3;
    if(t == 0) cout << "low";
    else if(t == 1) cout << "mid";
    else if(t == 2) cout << "high";
    return 0;
}