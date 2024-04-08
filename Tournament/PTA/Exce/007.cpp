#include<iostream>
#include<vector>
using namespace std;

string s[]{"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
vector<int> a;

int main()
{
    int n; cin >> n;
    if(n == 0) return cout << "ling" << endl, 0;
    if(n < 0) cout << "fu" << " ";
    n = abs(n);
    while(n){
        a.push_back(n % 10);
        n /= 10;
    }
    int size = a.size();
    for(int i = 1; i <= size; i++){
        cout << s[a.back()] << " "[i == size];
        a.pop_back();
    }
    cout << endl;
    return 0;
}