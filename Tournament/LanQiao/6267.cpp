#include<iostream>
using namespace std;

int main()
{
    int ans = 0;
    int i;
    for(i = 1; ans < 23; i++){
        int t = i;
        int res = 0;
        while(t){
            if(t & 1) res++;
            t >>= 1; 
        }
        if(res == 3) ans++;
    }
    cout << i-1 << endl; // 23
    return 0;
}