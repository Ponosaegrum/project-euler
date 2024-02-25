/* Ponosaegrum 25.02.2024 15:46:36 */

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

  const int N = 10000;
  vector<bool> is_prime(N + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= N; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
  auto valid = [&](int x, int y, int z) {
    if (!is_prime[x] || !is_prime[y] || !is_prime[z]) {
      return false;
    }
    string sx = to_string(x);
    string sy = to_string(y);
    string sz = to_string(z);
    sort(sx.begin(), sx.end());
    sort(sy.begin(), sy.end());
    sort(sz.begin(), sz.end());
    sx.erase(unique(sx.begin(), sx.end()), sx.end());
    sy.erase(unique(sy.begin(), sy.end()), sy.end());
    sz.erase(unique(sz.begin(), sz.end()), sz.end());
    return sx == sy && sx == sz && sy == sz;
  };
  for (int a1 = 1000; a1 <= 10000; ++a1) {
    for (int d = 1; d <= 5000 - a1 / 2; ++d) {
      int a2 = a1 + d;
      int a3 = a2 + d;
      if (valid(a1, a2, a3)) {
        cout << a1 << " " << a2 << " " << a3 << '\n';
      }
    }
  }
}
