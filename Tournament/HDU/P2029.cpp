#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n; scanf("%d", &n);
    while(n--){
        string str; cin >> str;
        bool ans = true;
        int i = 0, j = str.size() - 1;
        while(i < j){
            if(str[i] != str[j]){
                ans = false;
                break;
            }
            i++;
            j--;
        }
        if(ans) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}