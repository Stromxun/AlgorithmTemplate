#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    char c;
    cin >> n >> c;
    int t = round(n / 2.0);
    for(int i = 1; i <= t; i++){
        for(int j = 1; j <= n; j++){
            cout << c;
        }
        cout << endl;
    }
    return 0;
}