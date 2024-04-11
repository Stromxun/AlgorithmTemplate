#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

string s;

int main()
{
    char c;
    int cnt = 0;
    cin.get(c);
    while(c != EOF){
        if((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A')){
            cnt++;
        }else{
            if(cnt != 0) cout << cnt;
            cnt = 0;
        }
        cin.get(c);
    }
    cout << s;
    return 0;
}