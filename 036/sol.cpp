/* 11.02.2024 10:57:31 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  const int n = 1e6;
  auto solve_10 = [&](int x) {
    string s = to_string(x);
    int m = s.size();
    for (int i=0; i<m/2; i++) {
      if (s[i] != s[m-1-i]) {
        return false;
      }
    }
    return true;
  };
  auto solve_2 = [&](int x) {
    int len = log2(x)+1;
    for (int i=0; i<len/2; i++) {
      int r = (x & (1<<i)) > 0;
      int l = (x & (1 << (len-i-1))) > 0;
      if (l != r) {
        return false;
      }
    }
    return true;
  };
  long long sm = 0;
  for (int i=1; i<=n; i++) {
    if (solve_10(i) && solve_2(i)) {
//      cerr << i << '\n';
      sm += i;
    }
  }
  cout << sm << '\n';
}
