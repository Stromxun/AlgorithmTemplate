#include <iostream>
#include <algorithm>
using namespace std;
const int maxa = 1e5 + 10;
int a[maxa];

int main()
{
  // 请在此输入您的代码
  int n, k; cin >> n >> k;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  long long ans = 0;
  for(int i = 1; i + k - 1 <= n; i++){
    long long sum = 0;
    for(int j = i; j <= i + k - 1; j++){
        sum += a[j];
    }
    ans = max(sum, ans);
  }
  cout << ans;
  return 0;
}