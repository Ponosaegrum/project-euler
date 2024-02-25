/* Ponosaegrum 25.02.2024 16:37:16 */

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

  long long ans = 1;
  const long long mod = 10000000000;
  for (int i = 0; i < 7830457; ++i) {
    ans <<= 1;
    ans %= mod;
  }
  ans *= 28433;
  ans %= mod;
  ++ans;
  ans %= mod;
  cout << ans << '\n';
}
