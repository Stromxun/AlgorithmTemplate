#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  long long n; cin >> n;
  while(n >= 10){
    int t = n;
    int res = 1;
    while(t){
        if((t % 10) != 0)
            res = res * (t % 10);
        t /= 10;
    }
    n = res;
    cout << res << endl;
  }
  return 0;
}