/* 12.02.2024 22:06:50 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  auto check = [&](int x, int y) {
    string s = to_string(x), t = to_string(y);
    if (s[0] == t[0]) {
      s[0] = t[0] = '$';
    } else if (s[0] == t[1]) {
      s[0] = t[1] = '$';
    }
    if (s[1] == t[0]) {
      s[1] = t[0] = '$';
    } else if (s[1] == t[1]) {
      s[1] = t[1] = '$';
    }
    string _s, _t;
    for (char c : s) {
      if (c != '$') {
        _s += c;
      }
    }
    for (char c : t) {
      if (c != '$') {
        _t += c;
      }
    }
    if ((int)_s.size()!=1 || (int)_t.size()!=1) {
      return false;
    }
    int _x = stoi(_s), _y = stoi(_t);
    return (x*_y == y*_x);
  };
  for (int a=10; a<100; a++) {
    for (int b=a+1; b<100; b++) {
//      cerr << a << " " << b << '\n';
      if (check(a, b)) {
        cout << a << " " << b << '\n';
      }
    }
  }
}
