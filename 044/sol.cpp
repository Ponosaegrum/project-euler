/* Ponosaegrum 17.02.2024 17:17:43 */

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

  auto f = [&](long long n) {
    return n * (3 * n - 1) / 2;
  };
  vector<long long> p;
  const int n = 10000;
  for (int i = 1; i <= n; ++i) {
    p.emplace_back(f(i));
  }
  long long mn = 1.01e18;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      bool sum = binary_search(p.begin(), p.end(), p[i] + p[j]);
      bool diff = binary_search(p.begin(), p.end(), p[j] - p[i]);
      if (sum && diff) {
        mn = min(mn, p[j] - p[i]);
      }
    }
  }
  cout << mn << '\n';
}
