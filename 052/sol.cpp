/* Ponosaegrum 17.02.2024 15:07:18 */

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

  const int n = 1e8;
  auto solve = [&](long long x) {
    multiset<int> d;
    while (x) {
      int cur = x % 10;
      d.insert(cur);
      x /= 10;
    }
    return d;
  };
  for (long long i = 1; i <= n; ++i) {
    multiset<int> d = solve(i);
    bool good = true;
    for (int j = 2; j <= 6; ++j) {
      good &= (d == solve(j * i));
    }
    if (good) {
      cout << i << '\n';
      return 0;
    }
  }
}
