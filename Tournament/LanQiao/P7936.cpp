#include<iostream>
#include<algorithm>
using namespace std;

int sToInt(string s, int p)
{
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        char t = s[i];
        if(t >= '0' && t <= '9'){
            ans = ans * p + t - '0';
        }else{
            ans = ans * p + t - 'a' + 10;
        }
    }
    return ans;
}

string intToS(int num, int p)
{
    string s = "";
    while(num){
        int t = num % p;
        if(t >= 0 && t <= 9){
            s.push_back(t + '0');
        }else{
            s.push_back(t + 'a' - 10);
        }
        num /= p;
    }
    reverse(s.begin(), s.end());
    return s;
}

int slove(int num, int p)
{
    string s = intToS(num, p);
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        ans += s[i] - '0';
    }
    return ans;
}

int main()
{
    int n = 0, i;
    for(i = 1; n < 23; i++){
        if(slove(i, 2) == slove(i, 8)) n++;
    }
    cout << i - 1;
    return 0;
}