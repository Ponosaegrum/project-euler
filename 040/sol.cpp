/* 11.02.2024 12:57:38 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  for (int i=1; i<=1000000; i++) {
    s += to_string(i);
    if ((int)s.size() >= 1000000) {
      break;
    }
  }
  auto f = [&](char c) {
    return (int)(c - '0');
  };
  cout << f(s[9])*f(s[99])*f(s[999])*f(s[9999])*f(s[99999])*f(s[999999]) << '\n';
}
