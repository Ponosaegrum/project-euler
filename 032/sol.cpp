/* 12.02.2024 22:33:38 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  auto check = [&](int x, int y) {
    int z = x*y;
    string s = to_string(x), t = to_string(y), r = to_string(z);
    int n = s.size() + t.size() + r.size();
    if (n != 9) {
      return 0;
    }
    string check = "123456789";
    string cur = s + t + r;
    sort(cur.begin(), cur.end());
    if (cur == check) {
      cerr << "[x, y, z]: " << x << " " << y << " " << z << '\n';
    }
    return (cur==check ? z : 0);
  };
  set<int> ans;
  for (int a=0; a<=2000; a++) {
    for (int b=a; b<=2000; b++) {
      int cur = check(a, b);
      if (cur != 0) {
        ans.insert(cur);
      }
    }
  }
  long long sm = 0;
  for (int x : ans) {
//    cerr << x << " ";
    sm += x;
  }
  cout << sm << '\n';
}
