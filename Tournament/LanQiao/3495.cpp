#include<iostream>
#include<set>
using namespace std;

int nomal[] = {31,28,31,30,31,30,31,31,30,31,30,31};
set<int> s;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    for(int i = 1; i <= 12; i++){
        for(int j = 1; j <= nomal[i - 1]; j++){
            s.insert((i * j) / gcd(j, i));
        }
    }
    nomal[1]++;
    for(int i = 1; i <= 12; i++){
        for(int j = 1; j <= nomal[i - 1]; j++){
            s.insert((i * j) / gcd(j, i));
        }
    }
    for(int i = 2000; i <= 2000000; i++){
        
    }
}