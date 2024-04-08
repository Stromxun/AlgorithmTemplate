#include<iostream>
#include<cstring>
using namespace std;
const int MAXA = 2e1 + 5;
int dp[MAXA][MAXA];
bool isMatch(string s, string p) {
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < s.length(); i++){
        for(int j = 0; j < p.length(); j++){
            
        }
    }
}

int main()
{
    printf("%d\n", isMatch("aa", "a"));
}