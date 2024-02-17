/* Ponosaegrum 17.02.2024 16:42:34 */

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
  long long cur = 9;
  while (true) {
    bool ok = false;
    for (int i : prime) {
      if (i > cur) {
        break;
      }
      long long r = (cur - i) / 2;
      long long sq_r = sqrt(r);
      if (sq_r * sq_r == r) {
        ok = true;
        break;
      }
    }
    if (!ok) {
      cout << cur << '\n';
      return 0;
    }
    cur += 2;
    while (binary_search(prime.begin(), prime.end(), cur)) {
      cur += 2;
    }
  }
}
