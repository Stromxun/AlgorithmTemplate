#include<iostream>
using namespace std;

int a[10];

int main()
{
    char i;
    while(cin >> i){
        a[i - '0']++;
    }
    for(int i = 0; i <= 9; i++){
        if(a[i] == 0) continue;
        cout << i << ":" << a[i] << endl;  //输出数字及其出现次数
    }
    return 0;
}