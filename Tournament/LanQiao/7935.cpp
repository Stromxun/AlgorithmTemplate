#include<iostream>
using namespace std;

int main()
{
    int num = 2;
    for(int i = 2; i <= 2023; i++){
        num = num * 2;
        num = num % 1000;
    }
    cout << num << endl;
    return 0;
}