/* Ponosaegrum 17.02.2024 14:24:24 */

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
  #include "debug.h"
#else
  #define debug(...) 42
#endif

template <class... U>
auto create(size_t n, U&&... x)
{
  if constexpr (sizeof...(x) == 1)
    return vector(n, x...);
  else
    return vector(n, create(x...));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long mx = -1;
  int n = 1;
  function<void(int, vector<int>)> solve = [&](int c, vector<int> d) {
    if (c == n) {
      long long cur = 0;
      for (int i = 0; i < n; ++i) {
        cur *= 10;
        cur += d[i];
      }
//      debug(cur);
      bool good = true;
      for (long long i = 2; i * i <= cur; ++i) {
        if (cur % i == 0) {
          good = false;
          break;
        }
      }
      if (good) {
        mx = max(mx, cur);
      }
      return;
    }
    for (int i = 1; i <= n; ++i) {
      vector<int> _d = d;
      bool good = true;
      for (int j : _d) {
        if (j == i) {
          good = false;
          break;
        }
      }
      if (good) {
        _d.emplace_back(i);
        solve(c + 1, _d);
      }
    }
  };
  for (int i = 0; i < 9; ++i) {
    solve(0, {});
    ++n;
  }
  cout << mx << '\n';
}
