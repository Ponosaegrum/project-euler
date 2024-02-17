/* Ponosaegrum 17.02.2024 17:27:45 */

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
  auto check = [&](int x) {
//    debug(x);
    set<int> cur;
    for (int i : prime) {
      if (x % i == 0) {
        cur.insert(i);
        while (x % i == 0) {
          x /= i;
        }
      }
    }
    assert(x == 1);
//    debug(cur.size());
    return ((int) cur.size() == 4);
  };
  int first = 2;
  while (true) {
    if (check(first) && check(first + 1) && check(first + 2) && check(first + 3)) {
      cout << first << '\n';
      return 0;
    }
    ++first;
  }
}
