/* Ponosaegrum 17.02.2024 15:29:36 */

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

  const int N = 1e6;
  vector<bool> is_prime(N + 1, true);
  is_prime[0] = is_prime[1] = false;
  vector<int> prime;
  for (long long i = 2; i <= N; ++i) {
    if (is_prime[i]) {
      prime.emplace_back(i);
      for (long long j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
  int n = prime.size();
  vector<long long> qs(n + 1);
  for (int i = 0; i < n; ++i) {
    qs[i + 1] = qs[i] + prime[i];
  }
//  debug(n);
  int ans = -1;
  int mx = -1;
  for (int l = 1; l <= n; ++l) {
    for (int r = l; r <= n; ++r) {
      long long cur = qs[r] - qs[l - 1];
      int d = r - l + 1;
//      debug(l, r, ans, mx, cur, d);
      if (cur < N && is_prime[cur]) {
        if (d > mx) {
          mx = d;
          ans = cur;
        }
      }
    }
  }
  cout << ans << '\n';
}
