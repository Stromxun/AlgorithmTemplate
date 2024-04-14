#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  string s; cin >> s;
  s.push_back(s[0]);
  s.erase(0, 1);
  cout << s;
  return 0;
}