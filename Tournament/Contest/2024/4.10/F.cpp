#include<iostream>
#include<cstring>
using namespace std;

string t;

string gen1(string str)
{
    if(str[0] <= 'Z' && str[0] >= 'A') str[0] = str[0] - 'A' + 'a';
    for(int i = 1; i < str.size(); i++){
        if(str[i] == '_'){
            str[i + 1] = str[i + 1] - 'a' + 'A';
            str.erase(i, 1);
        }
    }
    return str;
}

string gen2(string str)
{
    if(str[0] <= 'z' && str[0] >= 'a') str[0] = str[0] - 'a' + 'A';
    for(int i = 1; i < str.size(); i++){
        if(str[i] == '_'){
            str[i + 1] = str[i + 1] - 'a' + 'A';
            str.erase(i, 1);
        }
    }
    return str;
}

string gen3(string str)
{
    if(str[0] <= 'Z' && str[0] >= 'A') str[0] = str[0] - 'A' + 'a';
    for(int i = 1; i < str.size(); i++){
        if(str[i] <= 'Z' && str[i] >= 'A'){
            str[i] = str[i] - 'A' + 'a';
            str.insert(i, "_");
        }
    }
    return str;
}

string gen(string str)
{
    if(t == "Camel") return gen1(str);
    else if(t == "Pascal") return gen2(str);
    else if(t == "Snake") return gen3(str);
    else return str;
}

int main()
{
    int n; cin >> n;
    cin >> t;
    for(int i = 1; i <= n; i++){
        string str;
        cin >> str;
        cout << gen(str) << endl;
    }
    return 0;
}