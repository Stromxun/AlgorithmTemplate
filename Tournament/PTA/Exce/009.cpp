#include<iostream>
using namespace std;

long long up, down, ansup, ansdown = 1;
char c;

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> up >> c >> down;
        ansup = ansup * down + up * ansdown;
        ansdown = ansdown * down;
        long long g = abs(gcd(ansup, ansdown));
        ansup /= g;
        ansdown /= g;
    }
    if(ansup % ansdown == 0){
        cout << ansup / ansdown << endl;
    }else{
        if(ansup / ansdown){
            cout << ansup / ansdown << " ";
        }
        cout << ansup - ansup / ansdown * ansdown << "/" << ansdown << endl;
    }
    return 0;
}