#include<iostream>
using namespace std;

long long n, ansr, ansl;

bool check(long long x)
{
    if(x == 1) return 0;
    if(x == 2 || x == 3) return 1;
    if(x % 6 != 1 && x % 6 != 5) return 0;
    for(long long i = 5; i * i <= x; i += 6){
        if(x % i == 0 || x % (i + 2) == 0) return 0;
    }
    return 1;
}

int main()
{
    cin >> n;
    if(check(n)) return cout << 1 << endl << n << endl, 0;
    for(long long i = 2; i * i <= n; i++){
        long long t = n, j = i;
        while(t % j == 0){
            t /= j;
            j++;
        }
        if((j - i) > (ansr - ansl)){
            ansr = j;
            ansl = i;
        }
    }
    cout << ansr - ansl << endl;
    for(long long i = ansl; i < ansr; i++){
        cout << i << "*"[i==ansr-1];
    }
    cout << endl;
    return 0;
}