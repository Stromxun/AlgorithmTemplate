#include<iostream>
#include<vector>
using namespace std;

vector<char> ans;
string a, b;

int cnt[200];

int main()
{
    getline(cin, a);
    getline(cin, b);
    int sizea = a.length(), sizeb = b.length();
    for(int i = 0; i < sizeb; i++){
        cnt[b[i]]++;
    }
    for(int i = 0; i < sizea; i++){
        if(cnt[a[i]] == 0){
            ans.push_back(a[i]);
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
    }
    cout << endl;
    return 0;
}