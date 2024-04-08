#include<iostream>
using namespace std;

int main()
{
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int i;
    cin >> i;
    cout << "Celsius = " << (5 * (i - 32)) / 9 << endl;
    return 0;
}