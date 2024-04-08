#include <iostream>
#include <deque>
#include <string.h>
using namespace std;
const long long maxa = 2e2 + 10;
long long a[maxa];
deque<long long> q;

int main()
{
    // 请在此输入您的代码
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int k; cin >> k;
    for(int i = n + 1; i <= k + n; i++) a[i] = maxa;
    for(int i = 1; i <= n + k; i++){
      while(!q.empty() && q.front() < i - 2 * k) q.pop_front();
      while(!q.empty() && a[q.back()] >= a[i]) q.pop_back();
      q.push_back(i);
      if(i > k) cout << a[q.front()] << " ";
    }
    return 0;
}