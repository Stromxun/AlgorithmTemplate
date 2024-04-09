#include<iostream>
using namespace std;

int main()
{
    long double l; cin >> l;
    int n = 0;
    while(l > 1){
        l /= 2;
        n++;
    }
    cout << n;
    return 0;
}