#include<iostream>
#include<string>
using namespace std;

string s;

void make(int l, int r)
{
    if(r > l){
        make(l, (l + r) / 2);
        make((l + r + 1) / 2, r);
    }
    int B = 1, I = 1;
    for(int i = 0; i <= r - l; i++){
        if(s[l + i] == '1') B = 0;
        else if(s[l + i] == '0') I = 0;
    }
    if(B) printf("B");
    else if(I) printf("I");
    else printf("F");
}

int main()
{
    int n; scanf("%d\n", &n);
    getline(cin, s);
    make(0, (1 << n) - 1);
    return 0;
}