#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int a, b; cin >> a >> b;
    int ans = 0;
    int cnt = 1;
    for(int i = a; i <= b; i++){
        cout << right << setw(5) << i;
        ans += i;
        if(cnt++ >= 5) cnt -= 5, cout << endl;
    }
    if(cnt != 1) cout << endl;
    cout << "Sum = " << ans << endl;
    return 0;
}