/* Ponosaegrum 17.02.2024 16:51:12 */

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

  long long sm = 0;
  vector<int> div = {2, 3, 5, 7, 11, 13, 17};
  function<void(int, vector<int>)> solve = [&](int cnt, vector<int> d) {
    if (cnt == 10) {
      bool ok = true;
      for (int i = 1, j = 0; i <= (int) d.size() - 3; ++i, ++j) {
        int cur = d[i] * 100 + d[i + 1] * 10 + d[i + 2];
        if (cur % div[j] != 0) {
          ok = false;
          break;
        }
      }
      if (ok) {
        long long cur = 0;
        for (int i : d) {
          cur *= 10;
          cur += i;
        }
        sm += cur;
      }
      return;
    }
    for (int i = (cnt == 0 ? 1 : 0); i <= 9; ++i) {
      vector<int> _d = d;
      bool good = true;
      for (int j : d) {
        if (i == j) {
          good = false;
          break;
        }
      }
      if (good) {
        _d.emplace_back(i);
        solve(cnt + 1, _d);
      }
    }
  };
  solve(0, {});
  cout << sm << '\n';
}
