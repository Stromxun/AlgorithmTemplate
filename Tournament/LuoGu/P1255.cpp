#include<iostream>
#include<algorithm>
using namespace std;

const int maxa = 5e3 + 10;
string a[maxa];

string add(string x, string y)
{
    int sizex = x.size(), sizey = y.size();
    string str;
    for(int i = 0; i < sizex || i < sizey; i++){
        if(!str[i]) str.push_back('0');
        int p = (sizex > i) ? (x[i] - '0') : 0;
        int q = (sizey > i) ? (y[i] - '0') : 0;
        str[i] = str[i] + p + q;
        if(str[i] > '9'){
            str.push_back('1');
            str[i] -= 10;
        }
    }
    return str;
}

string print(string str)
{
    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    int n; cin >> n;
    a[1] = "1", a[2] = "2";
    for(int i = 3; i <= n; i++){
        a[i] = add(a[i - 1], a[i - 2]);
    }
    cout << print(a[n]) << endl;
    return 0;
}